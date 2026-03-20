#include <iostream>
#include <opencv2/opencv.hpp>


int main(){
    // cv::Mat img;
    // img=cv::imread("/Users/sushantniraula/cpp_cv/exercise_1/bot.JPG");

    cv::Mat img = cv::imread("/Users/sushantniraula/cpp_cv/exercise_1/bot.JPG");
    /*
    Why it matters: In C++, when you write cv::Mat img;, 
    the compiler calls the default constructor for cv::Mat, allocating a small amount of memory for the matrix header. 
    On the very next line, the assignment operator = destroys or overwrites that initial state with the data from imread.
    By combining them into a single line (Initialization), you bypass the default constructor entirely. 
    In high-frequency vision loops (e.g., 60 frames per second), these micro-optimizations add up!
    */

    if (img.empty()){
        std::cerr<<"Error : Image not loaded! "<< std::endl;
        return -1;
    }

    cv::imshow("Agribot-Image", img);
    
    cv::waitKey(0);
    return 0;
}
