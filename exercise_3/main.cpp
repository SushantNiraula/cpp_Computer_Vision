#include <iostream>
#include <opencv2/opencv.hpp>

int main(){
    cv::Mat pure_blue(500,500, CV_8UC3, cv::Scalar(255, 0, 0));
    cv::imshow("Synthetic Vision", pure_blue);
    cv::waitKey(0);
    return 0;
}