#include <iostream>

#include <opencv2/core.hpp>

#include <opencv2/highgui.hpp>

using namespace std;

using namespace cv;

int main() {

  // Create a window to display the camera feed.

  namedWindow("Camera", WINDOW_AUTOSIZE);

  // Create a video capture object.

  VideoCapture cap(0);

  // Check if the camera is opened successfully.

  if (!cap.isOpened()) {

    cout << "Error opening the camera!" << endl;

    return -1;

  }

  // Create a timer to capture frames from the camera.

  int frame_rate = 30;

  int delay = 1000 / frame_rate;

  // Create a while loop to capture frames from the camera and display them on the window.

  while (true) {

    // Capture a frame from the camera.

    Mat frame;

    cap >> frame;

    // If the frame is empty, break out of the loop.

    if (frame.empty()) {

      break;

    }

    // Display the frame on the window.

    imshow("Camera", frame);

    // Wait for the user to press a key.

    int key = waitKey(delay);

    // If the user presses the Esc key, break out of the loop.

    if (key == 27) {

      break;

    }

  }

  // Close the window.

  destroyWindow("Camera");

  // Release the video capture object.

  cap.release();

  return 0;

}

