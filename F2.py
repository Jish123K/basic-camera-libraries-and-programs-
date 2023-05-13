import cv2

import numpy as np

import pyqtgraph as pg

# Create a QtGui application

app = QtGui.QApplication([])

# Create a window

window = QtGui.QMainWindow()

# Create a graphics layout

layout = pg.GraphicsLayoutWidget()

# Add a camera image item to the layout

image_item = pg.ImageItem()

layout.addItem(image_item)

# Create a camera object

camera = cv2.VideoCapture(0)

# Start the camera preview

while True:

    # Capture a frame from the camera

    ret, frame = camera.read()

    # Convert the frame to a NumPy array

    frame = np.array(frame)

    # Update the image item with the frame

    image_item.setImage(frame)

    # Check for the Esc key to exit

    if QtGui.QApplication.instance().keyboardModifiers() & QtCore.Qt.KeyModifier.ControlModifier:

        if QtGui.QApplication.instance().key() == QtCore.Qt.Key.Key_Escape:

            break

# Stop the camera preview

camera.release()

# Close the window

window.close()

# Exit the application

app.quit()

