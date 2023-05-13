import cv2

import numpy as np

import pygame

# Initialize the camera

camera = cv2.VideoCapture(0)

# Create the GUI window

screen = pygame.display.set_mode((640, 480))

# Create a surface to display the camera image

image_surface = pygame.Surface((640, 480))

# Create a button to take a picture

take_picture_button = pygame.Rect(10, 10, 100, 50)

# Create a label to display the current time

time_label = pygame.Surface((200, 50))

# Initialize the time variable

time = 0

# Start the main loop

while True:

    # Get a frame from the camera

    ret, frame = camera.read()

    # Convert the frame to grayscale

    grayscale_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Blur the grayscale frame

    blur_frame = cv2.GaussianBlur(grayscale_frame, (5, 5), 0)

    # Apply a threshold to the blurred frame

    threshold_frame = cv2.threshold(blur_frame, 127, 255, cv2.THRESH_BINARY)[1]

    # Find the contours in the thresholded frame

    contours, hierarchy = cv2.findContours(threshold_frame, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    # Find the largest contour

    largest_contour = max(contours, key=cv2.contourArea)

    # Get the bounding box of the largest contour

    bounding_box = cv2.boundingRect(largest_contour)

    # Draw the bounding box on the frame

    cv2.rectangle(frame, (bounding_box[0], bounding_box[1]), (bounding_box[0] + bounding_box[2], bounding_box[1] + bounding_box[3]), (0, 255, 0), 2)

    # Convert the frame to a pygame surface

    pygame_surface = pygame.image.frombuffer(frame, (640, 480), "RGB")

    # Copy the pygame surface to the image surface

    image_surface.blit(pygame_surface, (0, 0))

    # Draw the take picture button on the image surface

    pygame.draw.rect(image_surface, (0, 0, 255), take_picture_button)

    # Draw the time label on the image surface

    pygame.draw.text(image_surface, str(time), (200, 25), (0, 0, 0), 20)

    # Update the GUI window

    pygame.display.update()

    # Check for events

    for event in pygame.event.get():

        # If the user clicks on the take picture button

        if event.type == pygame.MOUSEBUTTONDOWN and event.button == 1 and take_picture_button.collidepoint(event.pos):

            # Save the current frame to a file

            cv2.imwrite("image.jpg", frame)

            # Increase the time variable

            time += 1

# Close the camera

camera.release()

# Quit pygame

pygame.quit()

