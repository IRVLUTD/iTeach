import os
import numpy as np
import torch
from torchvision import transforms
from PIL import Image
from scipy.stats import entropy
from scipy.stats import hmean
import matplotlib.pyplot as plt
from sklearn.preprocessing import MinMaxScaler

class FeatureLabelEntropyCalculator:
    def __init__(self):
        # Load DINOv2 model
        self.model = torch.hub.load('facebookresearch/dinov2', 'dinov2_vits14', pretrained=True)
        self.model.eval()
        
        # Define preprocessing transformations
        self.preprocess = transforms.Compose([
            transforms.Resize(224),
            transforms.CenterCrop(224),
            transforms.ToTensor(),
            transforms.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225]),
        ])

    def extract_features(self, image):
        """Extracts features using DINOv2 model."""
        image_tensor = self.preprocess(image).unsqueeze(0)
        with torch.no_grad():
            features = self.model(image_tensor).squeeze().cpu().numpy()
        return features

    def compute_feature_entropy(self, features):
        """Compute entropy of feature distributions."""
        flat_features = features.flatten()
        hist, bin_edges = np.histogram(flat_features, bins='auto', density=True)
        feature_entropy = entropy(hist + 1e-10)  # Add a small constant to avoid log(0)
        return feature_entropy

    def read_labels_from_file(self, file_path):
        """Read labels from a single YOLO format label file."""
        bboxes = []
        with open(file_path, 'r') as file:
            for line in file:
                parts = line.split()
                label = int(parts[0])
                x_center, y_center, width, height = map(float, parts[1:])
                bboxes.append((label, x_center, y_center, width, height))
        return bboxes

    def calculate_entropy(self, label_counts):
        """Calculate entropy given label counts."""
        total = sum(label_counts.values())
        if total == 0:
            return 0
        probabilities = [count / total for count in label_counts.values()]
        entropy_value = -sum(p * np.log2(p) for p in probabilities if p > 0)
        return entropy_value

    def aggregate_label_counts(self, labels_dir):
        """Aggregate label counts from all label files in a labels directory."""
        total_counts = {0: 0, 1: 0}
        if not os.path.isdir(labels_dir):
            return total_counts
        for file_name in os.listdir(labels_dir):
            if file_name.endswith('.txt'):
                file_path = os.path.join(labels_dir, file_name)
                file_counts = self.read_labels_from_file(file_path)
                for label in total_counts:
                    total_counts[label] += file_counts.get(label, 0)
        return total_counts

    def compute_label_entropy(self, labels_dir):
        """Compute label entropy for the labels directory."""
        label_counts = self.aggregate_label_counts(labels_dir)
        return self.calculate_entropy(label_counts)

    def extract_and_weight_features(self, image, bboxes):
        """Extract and weight features for cropped objects and entire image."""
        features_list = []
        weights = {'crop': 0.35, 'whole': 0.30}
        
        # Extract features for the whole image
        whole_image_features = self.extract_features(image)
        features_list.append(whole_image_features)

        # Extract features for cropped objects
        for bbox in bboxes:
            label, x_center, y_center, width, height = bbox
            # Convert normalized coordinates to pixel coordinates
            img_width, img_height = image.size
            x_min = int((x_center - width / 2) * img_width)
            x_max = int((x_center + width / 2) * img_width)
            y_min = int((y_center - height / 2) * img_height)
            y_max = int((y_center + height / 2) * img_height)

            # Crop the object
            cropped_image = image.crop((x_min, y_min, x_max, y_max))
            # Resize crop to the same size as preprocessing expects
            cropped_image = cropped_image.resize((224, 224))
            cropped_features = self.extract_features(cropped_image)
            features_list.append(cropped_features)
        
        # Combine features using the specified weights
        combined_features = np.mean(features_list[:1], axis=0) * weights['whole']
        if len(features_list) > 1:
            cropped_features = np.mean(features_list[1:], axis=0) * weights['crop']
            combined_features += cropped_features

        return combined_features

    def process_subdirectory(self, sub_dir):
        """Process images and labels from a single subdirectory."""
        images_dir = os.path.join(sub_dir, 'images')
        labels_dir = os.path.join(sub_dir, 'labels')
        
        features_list = []
        labels = []

        # Process images
        for file_name in os.listdir(images_dir):
            if file_name.endswith('.jpg'):
                image_path = os.path.join(images_dir, file_name)
                image = Image.open(image_path).convert('RGB')

                # Read bounding boxes
                label_file = file_name.replace('.jpg', '.txt')
                label_path = os.path.join(labels_dir, label_file)
                bboxes = self.read_labels_from_file(label_path) if os.path.exists(label_path) else []

                # Extract and weight features
                features = self.extract_and_weight_features(image, bboxes)
                features_list.append(features)

                if bboxes:
                    for label in bboxes:
                        labels.extend([label[0]] * 1)  # Modify this as per label counting logic
        
        if features_list:
            all_features = np.vstack(features_list)
            feature_entropy = self.compute_feature_entropy(all_features)
        else:
            feature_entropy = 0
        
        if labels:
            label_entropy = self.calculate_entropy({i: labels.count(i) for i in set(labels)})
        else:
            label_entropy = 0
        
        return feature_entropy, label_entropy

    def process_root_directory(self, root_dir):
        """Process all subdirectories and return results."""
        sub_dirs = [d for d in os.listdir(root_dir) if os.path.isdir(os.path.join(root_dir, d))]
        # Sort subdirectories by the first character of their names
        sub_dirs.sort(key=lambda d: d[0])
        results = {}
        for sub_dir in sub_dirs:
            sub_dir_path = os.path.join(root_dir, sub_dir)
            print(f"Processing {sub_dir_path}...")
            feature_entropy, label_entropy = self.process_subdirectory(sub_dir_path)
            results[sub_dir] = {
                'Feature Entropy': feature_entropy,
                'Label Entropy': label_entropy
            }
        return results

def compute_normalized_harmonic_mean(feature_entropies, label_entropies):
    """Compute normalized harmonic mean of feature and label entropies."""
    h_mean_values = []
    scaler = MinMaxScaler()

    for f_entropy, l_entropy in zip(feature_entropies, label_entropies):
        h_mean = hmean([f_entropy, l_entropy]) if f_entropy > 0 and l_entropy > 0 else 0
        h_mean_values.append(h_mean*100)
    
    # Normalize harmonic mean values
    h_mean_values = np.array(h_mean_values).reshape(-1, 1).round(2)
    normalized_h_mean = scaler.fit_transform(h_mean_values).flatten()

    return normalized_h_mean


def compute_harmonic_mean(feature_entropies, label_entropies):
    """Compute harmonic mean of feature and label entropies without normalization."""
    h_mean_values = []

    for f_entropy, l_entropy in zip(feature_entropies, label_entropies):
        h_mean = hmean([f_entropy, l_entropy]) if f_entropy > 0 and l_entropy > 0 else 0
        h_mean_values.append(h_mean * 100)  # Scaling the harmonic mean to amplify the values

    return np.array(h_mean_values)

def plot_normalized_entropies(results):
    """Plot the normalized harmonic mean of feature and label entropies as a line graph."""
    sub_dirs = list(results.keys())
    feature_entropies = [results[sub_dir]['Feature Entropy'] for sub_dir in sub_dirs]
    label_entropies = [results[sub_dir]['Label Entropy'] for sub_dir in sub_dirs]

    # Compute and normalize harmonic mean
    normalized_h_mean = compute_normalized_harmonic_mean(feature_entropies, label_entropies)

    print(normalized_h_mean)

    x = np.arange(len(sub_dirs))  # the label locations

    fig, ax = plt.subplots()
    ax.plot(x, normalized_h_mean, marker='o', linestyle='-', color='b', label='Normalized Harmonic Mean')

    ax.set_xlabel('Subdirectory')
    ax.set_ylabel('Normalized Harmonic Mean')
    ax.set_title('Normalized Harmonic Mean of Feature and Label Entropies')
    ax.set_xticks(x)
    ax.set_xticklabels(sub_dirs)
    ax.legend()

    plt.grid(True)
    plt.show()

def softmax(x):
    """Compute softmax values for a list of scores."""
    e_x = np.exp(x - np.max(x))  # Subtract max for numerical stability
    return e_x / e_x.sum(axis=0)


def compute_harmonic_mean_with_softmax(feature_entropies, label_entropies):
    """Compute harmonic mean of feature and label entropies and apply softmax."""
    h_mean_values = []

    for f_entropy, l_entropy in zip(feature_entropies, label_entropies):
        h_mean = hmean([f_entropy, l_entropy]) if f_entropy > 0 and l_entropy > 0 else 0
        h_mean_values.append(h_mean * 100)  # Scaling to amplify the values

    # Apply softmax to the harmonic mean values
    h_mean_values = np.array(h_mean_values)
    softmax_h_mean = softmax(h_mean_values)

    return softmax_h_mean


def plot_entropies(results):
    """Plot the softmax of the harmonic mean of feature and label entropies as a line graph."""
    sub_dirs = list(results.keys())
    feature_entropies = [results[sub_dir]['Feature Entropy'] for sub_dir in sub_dirs]
    label_entropies = [results[sub_dir]['Label Entropy'] for sub_dir in sub_dirs]

    # Compute harmonic mean with softmax
    softmax_h_mean = compute_harmonic_mean_with_softmax(feature_entropies, label_entropies)

    print(softmax_h_mean)

    x = np.arange(len(sub_dirs))  # the label locations

    fig, ax = plt.subplots()
    ax.plot(x, softmax_h_mean, marker='o', linestyle='-', color='b', label='Softmax Harmonic Mean')

    ax.set_xlabel('Subdirectory')
    ax.set_ylabel('Softmax Harmonic Mean')
    ax.set_title('Softmax Harmonic Mean of Feature and Label Entropies')
    ax.set_xticks(x)
    ax.set_xticklabels(sub_dirs)
    ax.legend()

    plt.grid(True)
    plt.show()



def plot_unnormalized_entropies(results):
    """Plot the harmonic mean of feature and label entropies as a line graph."""
    sub_dirs = list(results.keys())
    feature_entropies = [results[sub_dir]['Feature Entropy'] for sub_dir in sub_dirs]
    label_entropies = [results[sub_dir]['Label Entropy'] for sub_dir in sub_dirs]

    # Compute harmonic mean
    harmonic_mean = compute_harmonic_mean(feature_entropies, label_entropies)

    print(harmonic_mean)

    x = np.arange(len(sub_dirs))  # the label locations

    fig, ax = plt.subplots()
    ax.plot(x, harmonic_mean, marker='o', linestyle='-', color='b', label='Harmonic Mean')

    ax.set_xlabel('Subdirectory')
    ax.set_ylabel('Harmonic Mean')
    ax.set_title('Harmonic Mean of Feature and Label Entropies')
    ax.set_xticks(x)
    ax.set_xticklabels(sub_dirs)
    ax.legend()

    plt.grid(True)
    plt.show()


def main():
    """Main function to compute, print, and plot normalized harmonic mean of feature and label entropies."""
    
    root_dirs = [
        '/home/hololens/Projects/hololens/IRVLImageLabellingSupport/datasets/for-label-entropy/with-diversity-goal/hololens-labelled/atomic-new-samples',
        '/home/hololens/Projects/hololens/IRVLImageLabellingSupport/datasets/for-label-entropy/with-diversity-goal/desktop-app-labelled/atomic-new-samples',
        '/home/hololens/Projects/hololens/IRVLImageLabellingSupport/datasets/for-label-entropy/without-diversity-goal/desktop-app-labelled/atomic-new-samples'
    ]

    calc = FeatureLabelEntropyCalculator()
    
    for root_dir in root_dirs:
        results = calc.process_root_directory(root_dir)
        
        # for sub_dir, metrics in results.items():
        #     print(f"\nSubdirectory: {sub_dir}")
        #     print(f"Feature Entropy: {metrics['Feature Entropy']:.4f}")
        #     print(f"Label Entropy: {metrics['Label Entropy']:.4f}")

        # print(results)
        # Plot results
        plot_normalized_entropies(results)

if __name__ == "__main__":
    main()
