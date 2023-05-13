#include <iostream>

#include <vector>

#include <opencv2/core.hpp>

#include <opencv2/highgui.hpp>

using namespace std;

using namespace cv;

// This function initializes the camera and creates a GUI window.

void init() {

  // Open the camera.

  VideoCapture cap(0);

  if (!cap.isOpened()) {

    cout << "Error opening the camera!" << endl;

    return;

  }

  // Create a GUI window.

  namedWindow("Camera", WINDOW_AUTOSIZE);

}

// This function displays the current frame from the camera on the GUI window.

void display() {

  // Get the current frame from the camera.

  Mat frame;

  cap >> frame;

  // If the frame is empty, then the camera is not capturing any frames.

  if (frame.empty()) {

    return;

  }

  // Display the frame on the GUI window.

  imshow("Camera", frame);

}

// This function quits the application.

void quit() {

  // Close the GUI window.

  destroyWindow("Camera");

  // Close the camera.

  cap.release();

  // Exit the application.

  exit(0);

}

int main() {

  // Initialize the camera and create a GUI window.

  init();

  // Start a loop that displays the current frame from the camera on the GUI window.

  while (true) {

    // Display the current frame.

    display();

    // Check if the user has pressed the Esc key.

    if (waitKey(10) == 27) {

      // The user has pressed the Esc key, so quit the application.

      quit();

    }

  }

  // This should never be reached, but it's here for safety.

  return 0;

}

