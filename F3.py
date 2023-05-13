import tkinter as tk

from PIL import Image, ImageTk

import picamera

# Create the main window

root = tk.Tk()

root.title("Basic Camera")

# Create the canvas

canvas = tk.Canvas(root, width=640, height=480)

canvas.pack()

# Create the camera object

camera = picamera.PiCamera()

camera.resolution = (640, 480)

# Start the camera preview

camera.start_preview()

# Create a function to update the image on the canvas

def update_image():

    # Get the latest image from the camera

    image = camera.capture()

    # Convert the image to a PIL image

    pil_image = Image.fromarray(image)

    # Scale the image to the size of the canvas

    scaled_image = pil_image.resize((640, 480))

    # Create a new ImageTk image from the PIL image

    tk_image = ImageTk.PhotoImage(scaled_image)

    # Update the image on the canvas

    canvas.create_image(0, 0, image=tk_image, anchor=tk.NW)

# Create a timer to update the image every 100ms

timer = tk.Timer(100, update_image)

timer.start()

# Start the main loop

root.mainloop()

