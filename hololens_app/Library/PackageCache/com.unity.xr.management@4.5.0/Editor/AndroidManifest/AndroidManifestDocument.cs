using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using System.Xml;

namespace Unity.XR.Management.AndroidManifest.Editor
{
    /// <summary>
    /// This class holds information that should be displayed in an Editor tooltip for a given package.
    /// </summary>
    internal class AndroidManifestDocument : XmlDocument
    {
        internal static readonly string k_androidXmlNamespace = "http://schemas.android.com/apk/res/android";

        private readonly string m_Path;
        private readonly XmlNamespaceManager m_nsMgr;

        internal AndroidManifestDocument()
        {
            m_nsMgr = new XmlNamespaceManager(NameTable);
            m_nsMgr.AddNamespace("android", k_androidXmlNamespace);
        }

        internal AndroidManifestDocument(string path)
        {
            m_Path = path;

            using (var reader = new XmlTextReader(m_Path))
            {
                reader.Read();
                Load(reader);
            }

            m_nsMgr = new XmlNamespaceManager(NameTable);
            m_nsMgr.AddNamespace("android", k_androidXmlNamespace);
        }

        internal string Save()
        {
            return SaveAs(m_Path);
        }

        internal string SaveAs(string path)
        {
            // ensure the folder exists so that the XmlTextWriter doesn't fail
            Directory.CreateDirectory(Path.GetDirectoryName(path));
            using (var writer = new XmlTextWriter(path, new UTF8Encoding(false)))
            {
                writer.Formatting = Formatting.Indented;
                Save(writer);
            }

            return path;
        }

        internal void CreateNewElement(List<string> path, Dictionary<string, string> attributes)
        {
            // Look up for closest parent node to new leaf node
            XmlElement parentNode, node = null;
            int nextNodeIndex = -1;
            do
            {
                nextNodeIndex++;
                parentNode = node;
                node = (XmlElement)(parentNode == null ?
                     SelectSingleNode(path[nextNodeIndex]) :
                    parentNode.SelectSingleNode(path[nextNodeIndex]));
            } while (node != null && nextNodeIndex < path.Count - 1);

            // If nodes are missing between root and leaf, fill out hierarchy including leaf node
            for (int i = nextNodeIndex; i < path.Count; i++)
            {
                node = CreateElement(path[i]);
                parentNode.AppendChild(node);
                parentNode = node;
            }

            // Apply attributes to leaf node
            foreach (var attributePair in attributes)
            {
                node.SetAttribute(attributePair.Key, k_androidXmlNamespace, attributePair.Value);
            }
        }

        internal struct PathNode
        {
            public XmlElement parent;
            public XmlElement node;
            public int DepthIndex;
        };

        internal void CreateNewElementInAllPaths(List<string> path, Dictionary<string, string> attributes)
        {
            // Nodes that match the path, just need to add attributes
            var nodesToEdit = new List<XmlElement>();
            // Nodes that are missing the full path, hence, the desired node and its parents should be created
            var incompletePathNodes = new List<PathNode>();

            var nodesToCheckQueue = new Queue<PathNode>();
            if (DocumentElement.Name.Equals(path.First()))
            {
                nodesToCheckQueue.Enqueue(new PathNode { parent = null, node = DocumentElement, DepthIndex = 0 });
            }
            else
            {
                incompletePathNodes.Add(new PathNode { parent = null, node = DocumentElement, DepthIndex = 0 });
            }

            var targetNodeName = path.Last();

            while (nodesToCheckQueue.Any())
            {
                var currentNode = nodesToCheckQueue.Dequeue();

                var nextPathIndex = currentNode.DepthIndex + 1;

                if (currentNode.node.ChildNodes.Count == 0 || nextPathIndex >= path.Count)
                {
                    // No children left, needs to add elements to complete the path
                    var incompletePathNode = targetNodeName.Equals(currentNode.node.Name) ?
                        // There's a node with the same name, but attributes don't match
                        new PathNode { node = currentNode.parent, DepthIndex = currentNode.DepthIndex - 1 } :
                        // No node with the same name, create nodes in the path
                        currentNode;
                    incompletePathNodes.Add(incompletePathNode);
                    continue;
                }

                // Select only children that match the next path element
                var matchingPathChildNodes = currentNode.node.SelectNodes(path[nextPathIndex]);

                // Find if a matching child node with the attributes exists
                bool foundMatchingNode = false;
                foreach (XmlElement childNode in matchingPathChildNodes)
                {
                    if(targetNodeName.Equals(childNode.Name) && CheckNodeAttributesMatch(childNode, attributes))
                    {
                        foundMatchingNode = true;
                        break;
                    }
                }

                // If no matching node was found, add all children to the queue to continue searching
                if (!foundMatchingNode)
                {
                    foreach (XmlElement childNode in matchingPathChildNodes)
                    {
                        nodesToCheckQueue.Enqueue(new PathNode { parent = currentNode.node, node = childNode, DepthIndex = nextPathIndex });
                    }
                }
            }

            foreach (var incompletePathNode in incompletePathNodes)
            {
                var parentNode = incompletePathNode.node;
                XmlElement newNode = null;
                // If nodes are missing between root and leaf, fill out hierarchy including leaf node
                for (var i = incompletePathNode.DepthIndex + 1; i < path.Count; i++)
                {
                    newNode = CreateElement(path[i]);
                    parentNode.AppendChild(newNode);
                    parentNode = newNode;
                }
                if (newNode != null)
                {
                    // Only add new nodes that were created
                    nodesToEdit.Add(parentNode);
                }
            }

            foreach (var node in nodesToEdit)
            {
                // Apply attributes to leaf node
                foreach (var attributePair in attributes)
                {
                    node.SetAttribute(attributePair.Key, k_androidXmlNamespace, attributePair.Value);
                }
            }
        }

        internal void CreateNewElementIfDoesntExist(List<string> path, Dictionary<string, string> attributes)
        {
            if (!ElementExists(path, attributes))
            {
                CreateNewElement(path, attributes);
            }
        }

        internal void CreateOrOverrideElement(List<string> path, Dictionary<string, string> attributes)
        {
            // Look up for leaf node or closest
            XmlElement parentNode, node = null;
            int nextNodeIndex = -1;
            do
            {
                nextNodeIndex++;
                parentNode = node;
                node = (XmlElement)(parentNode == null ?
                     SelectSingleNode(path[nextNodeIndex]) :
                    parentNode.SelectSingleNode(path[nextNodeIndex]));
            } while (node != null && nextNodeIndex < path.Count - 1);

            // If nodes are missing between root and leaf, fill out hierarchy including leaf node
            if (node == null)
            {
                for (int i = nextNodeIndex; i < path.Count; i++)
                {
                    node = CreateElement(path[i]);
                    parentNode.AppendChild(node);
                    parentNode = node;
                }
            }

            // Apply attributes to leaf node
            foreach (var attributePair in attributes)
            {
                node.SetAttribute(attributePair.Key, k_androidXmlNamespace, attributePair.Value);
            }
        }

        internal void RemoveMatchingElement(List<string> elementPath, Dictionary<string, string> attributes)
        {
            var xmlNodeList = SelectNodes(string.Join("/", elementPath));

            foreach (XmlElement node in xmlNodeList)
            {
                if (CheckNodeAttributesMatch(node, attributes))
                {
                    node.ParentNode?.RemoveChild(node);
                }
            }
        }

        private bool CheckNodeAttributesMatch(XmlNode node, Dictionary<string, string> attributes)
        {
            var nodeAttributes = node.Attributes;
            foreach (XmlAttribute attribute in nodeAttributes)
            {
                var rawAttributeName = attribute.Name.Split(':').Last();
                if (!attributes.Contains(new KeyValuePair<string, string>(rawAttributeName, attribute.Value)))
                {
                    return false;
                }
            }
            return true;
        }

        internal void CreateElements(IEnumerable<ManifestElement> newElements, bool allowDuplicates = true)
        {
            if(allowDuplicates)
            {
                foreach (var requirement in newElements)
                {
                    this
                        .CreateNewElement(
                        requirement.ElementPath, requirement.Attributes);
                }
            }
            else
            {
                foreach (var requirement in newElements)
                {
                    this
                        .CreateNewElementIfDoesntExist(
                        requirement.ElementPath, requirement.Attributes);
                }
            }
        }

        internal void OverrideElements(IEnumerable<ManifestElement> overrideElements)
        {
            foreach (var requirement in overrideElements)
            {
                var matchingNodes = SelectNodes(string.Join("/", requirement.ElementPath));
                if (matchingNodes.Count == 0)
                {
                    this.CreateOrOverrideElement(
                        requirement.ElementPath, requirement.Attributes);
                }
                else
                {
                    foreach (XmlElement node in matchingNodes)
                    {
                        foreach (var attributePair in requirement.Attributes)
                        {
                            node.SetAttribute(attributePair.Key, k_androidXmlNamespace, attributePair.Value);
                        }
                    }
                }
            }
        }

        internal void RemoveElements(IEnumerable<ManifestElement> removableElements)
        {
            foreach (var requirement in removableElements)
            {
                this
                    .RemoveMatchingElement(
                    requirement.ElementPath, requirement.Attributes);
            }
        }

        private bool ElementExists(List<string> path, Dictionary<string, string> attributes)
        {
            var existingNodeElements = SelectNodes(string.Join("/", path));
            foreach (XmlElement element in existingNodeElements)
            {
                if (CheckNodeAttributesMatch(element, attributes))
                {
                    return true;
                }
            }

            return false;
        }
    }
}
