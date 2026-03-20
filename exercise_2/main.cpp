#include <iostream>
#include <opencv2/opencv.hpp>

int main(){
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open the webcam feed!!" << std::endl;
        return -1; // Exit immediately
    }
    cv::Mat frame;
    while (true) {
        cap >> frame;
        cv::imshow("webcam-feed", frame);
        if (cv::waitKey(1) == 'q') break;
    }
    cap.release(); // Explicitly release hardware resources (Good practice)
    cv::destroyAllWindows(); // Clean up GUI memory
    return 0;
}