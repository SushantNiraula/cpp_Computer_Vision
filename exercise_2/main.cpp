#include <iostream>
#include <opencv2/opencv.hpp>

int main(){
    cv::VideoCapture cap(0);
    cv::Mat frame;
    if (cap.isOpened()){
        while (true){
            cap>>frame;
            cv::imshow("webcam-feed", frame);

            //Wait 1 millisecond for user input. If 'q' is pressed, break the loop.
            if (cv::waitKey(1)=='q') { 
            break;
            }
        }
    }
    else{
        std::cerr<<"Couldnot open the webcam feed !!"<<std::endl;
        return -1;
    }
    return 0;
}