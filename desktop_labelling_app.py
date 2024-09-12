from __future__ import division
from tkinter import *  # Updated import for Python 3
from tkinter import messagebox  # Updated import for Python 3
from PIL import Image, ImageTk
import os
import glob
import random

# colors for the bboxes
COLORS = {0: 'red', 1: 'yellow'}  # Red for Door, Yellow for Handle

class LabelTool():
    def __init__(self, master):
        # set up the main frame
        self.parent = master
        self.parent.title("LabelTool")
        self.frame = Frame(self.parent)
        self.frame.pack(fill=BOTH, expand=0)
        self.parent.resizable(width=True, height=True)

        # initialize global state
        self.imageDir = '/home/jishnu/Projects/IRVLImageLabellingSupport/datasets/emulate_datasets/images'  # Default path
        self.imageList = []
        self.egDir = ''
        self.egList = []
        self.outDir = ''
        self.cur = 0
        self.total = 0
        self.labeling_mode = None
        self.imagename = ''
        self.labelfilename = ''
        self.tkimg = None

        # initialize mouse state
        self.STATE = {}
        self.STATE['click'] = 0
        self.STATE['x'], self.STATE['y'] = 0, 0

        # reference to bbox
        self.bboxIdList = []
        self.bboxId = None
        self.bboxList = []
        self.bboxLabels = {}  # New dictionary to keep track of labels for each bbox
        self.hl = None
        self.vl = None

        # ----------------- GUI stuff ---------------------
        # dir entry & load
        self.label = Label(self.frame, text="Image Dir:")
        self.label.grid(row=0, column=0, sticky=E)
        self.entry = Entry(self.frame)
        self.entry.grid(row=0, column=1, sticky=W+E)
        self.ldBtn = Button(self.frame, text="Load", command=self.loadDir)
        self.ldBtn.grid(row=0, column=2, sticky=W+E)

        # main panel for labeling
        self.mainPanel = Canvas(self.frame, cursor='tcross', bg='white')
        self.mainPanel.grid(row=1, column=1, rowspan=4, sticky=N+S+E+W)
        self.mainPanel.bind("<Button-1>", self.mouseClick)
        self.mainPanel.bind("<Motion>", self.mouseMove)
        self.parent.bind("<Escape>", self.cancelBBox)  # press <Escape> to cancel current bbox
        self.parent.bind("s", self.cancelBBox)
        self.parent.bind("a", self.prevImage)  # press 'a' to go backward
        self.parent.bind("d", self.nextImage)  # press 'd' to go forward

        # Inside the __init__ method of LabelTool
        self.lb1 = Label(self.frame, text='Bounding boxes:')
        self.lb1.grid(row=1, column=2, sticky=W+N)

        self.listbox = Listbox(self.frame, width=40, height=20)  # Increased size
        self.listbox.grid(row=2, column=2, sticky=N)
        self.listbox.bind("<ButtonRelease-1>", self.highlightBBox)  # Bind click event

        self.btnDel = Button(self.frame, text='Delete', command=self.delBBox)
        self.btnDel.grid(row=3, column=2, sticky=W+E+N)
        self.btnClear = Button(self.frame, text='ClearAll', command=self.clearBBox)
        self.btnClear.grid(row=4, column=2, sticky=W+E+N)

        # Labeling mode buttons
        self.btnLabelDoor = Button(self.frame, text='Label Door', command=self.setLabelDoor)
        self.btnLabelDoor.grid(row=5, column=2, sticky=W+E+N)
        self.btnLabelHandle = Button(self.frame, text='Label Handle', command=self.setLabelHandle)
        self.btnLabelHandle.grid(row=6, column=2, sticky=W+E+N)

        # control panel for image navigation
        self.ctrPanel = Frame(self.frame)
        self.ctrPanel.grid(row=7, column=1, columnspan=2, sticky=W+E)
        self.prevBtn = Button(self.ctrPanel, text='<< Prev', width=10, command=self.prevImage)
        self.prevBtn.pack(side=LEFT, padx=5, pady=3)
        self.nextBtn = Button(self.ctrPanel, text='Next >>', width=10, command=self.nextImage)
        self.nextBtn.pack(side=LEFT, padx=5, pady=3)
        self.progLabel = Label(self.ctrPanel, text="Progress:     /    ")
        self.progLabel.pack(side=LEFT, padx=5)
        self.tmpLabel = Label(self.ctrPanel, text="Go to Image No.")
        self.tmpLabel.pack(side=LEFT, padx=5)
        self.idxEntry = Entry(self.ctrPanel, width=5)
        self.idxEntry.pack(side=LEFT)
        self.goBtn = Button(self.ctrPanel, text='Go', command=self.gotoImage)
        self.goBtn.pack(side=LEFT)

        # example panel for illustration
        self.egPanel = Frame(self.frame, border=10)
        self.egPanel.grid(row=1, column=0, rowspan=5, sticky=N)
        self.tmpLabel2 = Label(self.egPanel, text="Examples:")
        self.tmpLabel2.pack(side=TOP, pady=5)
        self.egLabels = []
        for i in range(3):
            self.egLabels.append(Label(self.egPanel))
            self.egLabels[-1].pack(side=TOP)

        # display mouse position
        self.disp = Label(self.ctrPanel, text='')
        self.disp.pack(side=RIGHT)

        # Add Save button
        self.btnSave = Button(self.frame, text='Save', command=self.saveBBox)
        self.btnSave.grid(row=8, column=2, sticky=W+E+N)

        self.frame.columnconfigure(1, weight=1)
        self.frame.rowconfigure(4, weight=1)
        
        # Bind resize event to update the canvas and image
        self.parent.bind("<Configure>", self.on_resize)

    def on_resize(self, event):
        # Update the canvas size and reload the image
        self.mainPanel.config(width=self.parent.winfo_width() - self.frame.winfo_x(),
                             height=self.parent.winfo_height() - self.frame.winfo_y())
        self.loadImage()

    def setLabelDoor(self):
        self.labeling_mode = 0  # 0 for Door

    def setLabelHandle(self):
        self.labeling_mode = 1  # 1 for Handle

    def highlightBBox(self, event):
        index = self.listbox.curselection()
        if index:
            index = index[0]
            bbox_id = self.bboxIdList[index]

            # Clear previous highlights
            if self.hl:
                self.mainPanel.delete(self.hl)

            # Draw new highlight
            bbox_coords = self.mainPanel.coords(bbox_id)
            self.hl = self.mainPanel.create_rectangle(
                bbox_coords, outline='cyan', width=2, stipple='gray50', dash=(4, 4)
            )
            self.mainPanel.tag_raise(self.hl)

    def delBBox(self):
        selected = self.listbox.curselection()
        if selected:
            index = selected[0]
            if index < len(self.bboxIdList):
                bbox_id = self.bboxIdList[index]
                self.mainPanel.delete(bbox_id)
                del self.bboxIdList[index]
                del self.bboxList[index]
                self.bboxLabels.pop(index, None)  # Use pop() to avoid KeyError
                self.listbox.delete(index)
                if self.hl:
                    self.mainPanel.delete(self.hl)

                # Adjust remaining indices
                for i in range(index, len(self.bboxIdList)):
                    self.bboxLabels[i] = self.bboxLabels.get(i + 1, 0)  # Fix index in bboxLabels


    def updateImageDirToLabels(self):
        # Split the image directory path by '/'
        path_parts = self.imageDir.split('/')

        # Replace the last entry with 'labels'
        path_parts[-1] = 'labels'

        return '/'.join(path_parts)


    def loadDir(self, dbg=True):
        if not dbg:
            s = self.entry.get()
            self.parent.focus()
            self.imageDir = s  # Use the path directly
        else:
            self.imageDir = '/home/jishnu/Projects/IRVLImageLabellingSupport/datasets/hololens_data_store/images'

        # Check if directory exists
        if not os.path.isdir(self.imageDir):
            print('The specified directory does not exist!')
            return

        # get image list
        self.imageList = glob.glob(os.path.join(self.imageDir, '*.png'))
        if len(self.imageList) == 0:
            print('No .png images found in the specified dir!')
            return

        # default to the 1st image in the collection
        self.cur = 1
        self.total = len(self.imageList)

        # set up output dir
        self.outDir = self.updateImageDirToLabels()#os.path.join(r'./labels')
        if not os.path.exists(self.outDir):
            os.mkdir(self.outDir)

        self.loadImage()
        # print('%d images loaded from %s' % (self.total, s))


    def loadBBox(self):
        # Clear existing bounding boxes before loading new ones
        self.mainPanel.delete("bbox")
        self.bboxIdList = []
        self.bboxList = []
        self.bboxLabels = {}
        self.listbox.delete(0, END)

        if not os.path.isfile(self.labelfilename):
            return

        with open(self.labelfilename, 'r') as file:
            for line in file:
                parts = line.strip().split()
                if len(parts) == 5:
                    label, cx, cy, w, h = map(float, parts)
                    x0 = (cx - w / 2) * self.tkimg.width()
                    y0 = (cy - h / 2) * self.tkimg.height()
                    x1 = (cx + w / 2) * self.tkimg.width()
                    y1 = (cy + h / 2) * self.tkimg.height()

                    bbox_id = self.mainPanel.create_rectangle(
                        x0, y0, x1, y1, outline=COLORS[int(label)], width=2, tag="bbox"
                    )
                    self.bboxIdList.append(bbox_id)
                    self.bboxList.append((x0, y0, x1, y1))
                    self.bboxLabels[len(self.bboxList) - 1] = int(label)
                    bbox_label_name = 'Door' if label == 0 else 'Handle'
                    self.listbox.insert(END, f"{bbox_label_name}: {x0} {y0} {x1} {y1}")


    def loadImage(self):
        if self.cur <= 0 or self.cur > len(self.imageList):
            return
        
        imagePath = self.imageList[self.cur - 1]
        self.imagename = os.path.basename(imagePath)
        self.labelfilename = os.path.join(self.outDir, os.path.splitext(self.imagename)[0] + '.txt')
        
        # Open and resize image according to canvas size
        img = Image.open(imagePath)
        canvas_width = self.mainPanel.winfo_width()
        canvas_height = self.mainPanel.winfo_height()
        img = img.resize((canvas_width, canvas_height), Image.ANTIALIAS)
        
        # Convert image to PhotoImage
        self.tkimg = ImageTk.PhotoImage(img)
        
        self.mainPanel.create_image(0, 0, image=self.tkimg, anchor=NW)

        # Load and draw bounding boxes from label file if it exists
        self.loadBBox()

    def saveBBox(self):
        # Normalize and save bounding boxes with their labels
        with open(self.labelfilename, 'w') as file:
            for i, bbox in enumerate(self.bboxList):
                x0, y0, x1, y1 = bbox
                width = x1 - x0
                height = y1 - y0
                cx = (x0 + x1) / 2 / self.tkimg.width()
                cy = (y0 + y1) / 2 / self.tkimg.height()
                w = width / self.tkimg.width()
                h = height / self.tkimg.height()
                label = self.bboxLabels.get(i, 0)  # Get label for the bbox, default to 0
                file.write(f"{label} {cx} {cy} {w} {h}\n")
        messagebox.showinfo("Save", "Bounding boxes saved successfully!")

    def mouseClick(self, event):
        if self.labeling_mode is None:
            messagebox.showinfo("No Labeling Mode", "Please select a labeling mode (Door or Handle) before drawing a bounding box.")
            return

        if self.STATE['click'] == 0:
            self.STATE['x'], self.STATE['y'] = event.x, event.y
            self.bboxId = self.mainPanel.create_rectangle(
                event.x, event.y, event.x, event.y, outline=COLORS[self.labeling_mode], width=2, tag="bbox"
            )
            self.STATE['click'] = 1
        else:
            x1, y1 = event.x, event.y
            self.mainPanel.coords(self.bboxId, self.STATE['x'], self.STATE['y'], x1, y1)
            bbox_coords = self.mainPanel.coords(self.bboxId)
            self.bboxList.append((bbox_coords[0], bbox_coords[1], bbox_coords[2], bbox_coords[3]))
            bbox_label = self.labeling_mode
            self.bboxLabels[len(self.bboxList) - 1] = bbox_label  # Assign the label to the bbox
            bbox_label_name = 'Door' if bbox_label == 0 else 'Handle'
            self.listbox.insert(END, f"{bbox_label_name}: {bbox_coords[0]} {bbox_coords[1]} {bbox_coords[2]} {bbox_coords[3]}")
            self.bboxIdList.append(self.bboxId)
            self.STATE['click'] = 0
            self.bboxId = None

    def mouseMove(self, event):
        if self.STATE['click'] == 1:
            self.mainPanel.coords(self.bboxId, self.STATE['x'], self.STATE['y'], event.x, event.y)

    def cancelBBox(self, event=None):
        if self.bboxId:
            self.mainPanel.delete(self.bboxId)
            self.bboxId = None
            self.STATE['click'] = 0

    def clearBBox(self):
        for bbox_id in self.bboxIdList:
            self.mainPanel.delete(bbox_id)
        self.bboxIdList = []
        self.bboxList = []
        self.bboxLabels = {}
        self.listbox.delete(0, END)
        if self.hl:
            self.mainPanel.delete(self.hl)

    def prevImage(self, event=None):
        if self.cur > 1:
            self.cur -= 1
            self.loadImage()

    def nextImage(self, event=None):
        if self.cur < self.total:
            self.cur += 1
            self.loadImage()

    def gotoImage(self):
        idx = self.idxEntry.get()
        if idx.isdigit():
            idx = int(idx)
            if 1 <= idx <= self.total:
                self.cur = idx
                self.loadImage()
            else:
                messagebox.showerror("Index Error", "Image index out of range.")
        else:
            messagebox.showerror("Input Error", "Invalid input. Please enter a number.")

# Example usage
if __name__ == "__main__":
    root = Tk()
    app = LabelTool(root)
    root.mainloop()
