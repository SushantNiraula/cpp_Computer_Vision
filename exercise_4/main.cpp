#include <iostream>
#include <opencv2/opencv.hpp>

cv::Mat static_HUD(){
    //width 800, height 600 so first height then width for canvas
    cv::Mat black_image(600, 800, CV_8UC3, cv::Scalar(255, 255, 255));
    //Drawing a crosshair
    cv::line(black_image, cv::Point(380, 300),cv::Point(420, 300), cv::Scalar(0, 0, 0), 2 );
    cv::line(black_image, cv::Point(400, 280), cv::Point(400, 320), cv::Scalar(0, 0, 0), 2);

    //Drawing a rectangle on the top right quadrant of screen.(50*30)pixels in size
    cv::rectangle(black_image, cv::Point(450, 20), cv::Point(750, 100), cv::Scalar(0, 0, 0), 2 );

    // Putting the text "TARGETED_TEXT"
    cv::putText(black_image,"TARGETED_TEXT", cv::Point(485, 70), cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(0,0,255), 2 );

    return black_image;
}

cv::Mat dynamic_HUD(int height, int width){
    int center_x = width/2;
    int center_y = height/2;
    //width 800, height 600 so first height then width for canvas
    cv::Mat black_image(height, width, CV_8UC3, cv::Scalar(255, 255, 255));
    //Drawing a crosshair
    cv::line(black_image, cv::Point(center_x-20,center_y),cv::Point(center_x+20, center_y), cv::Scalar(0, 0, 0), 2 );
    cv::line(black_image, cv::Point(center_x, center_y-20), cv::Point(center_x, center_y+20), cv::Scalar(0, 0, 0), 2);

    //Drawing a rectangle on the top right quadrant of screen.(50*30)pixels in size
    cv::rectangle(black_image, cv::Point(center_x+20, 20), cv::Point(center_x+150, 100), cv::Scalar(0, 0, 0), 2 );

    // Putting the text "TARGETED_TEXT"
    cv::putText(black_image,"TARGETED_TEXT", cv::Point(center_x+85, 70), cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(0,0,255), 2 );

    return black_image;
}

cv::Mat dynamic_HUD2(cv::Mat black_image){
    /*
    The C++ Inefficiency (Pass-by-Value): When you write cv::Mat black_image as a parameter,
     you are passing the matrix by value. While OpenCV is smart and won't copy the millions of
    actual pixels (it uses smart pointers internally), it does copy the matrix header
    (size, type, pointer data) every single time you call this function.
     In a 60 FPS loop, this is unnecessary overhead.
     
     Furthermore, because you passed it by value,
      you modified a local copy of the header and then had to return it.

      The Modern C++ Standard (Pass-by-Reference):
    If a function needs to modify an existing image, we pass it by reference using the & symbol.
    This creates zero copies and modifies the original object directly in memory.
    We also change the return type to void because the original matrix is being updated in-place!
     
    
    void dynamic_HUD2(cv::Mat& image) no need to return as original one will be edited. 
    
    */
    int center_x = black_image.cols/2;
    int center_y = black_image.rows/2;

    //Drawing a crosshair
    cv::line(black_image, cv::Point(center_x-20,center_y),cv::Point(center_x+20, center_y), cv::Scalar(0, 0, 0), 2 );
    cv::line(black_image, cv::Point(center_x, center_y-20), cv::Point(center_x, center_y+20), cv::Scalar(0, 0, 0), 2);

    //Drawing a rectangle on the top right quadrant of screen.(50*30)pixels in size
    cv::rectangle(black_image, cv::Point(center_x+20, 20), cv::Point(center_x+150, 100), cv::Scalar(0, 0, 0), 2 );

    // Putting the text "TARGETED_TEXT"
    cv::putText(black_image,"TARGETED_TEXT", cv::Point(center_x+85, 70), cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(0,0,255), 2 );

    return black_image;


}

int main(){
    
    cv::Mat black_image = static_HUD();

    cv::Mat black_image2 = dynamic_HUD(600, 800);


    cv::Mat black_image3(600, 800, CV_8UC3, cv::Scalar(255, 255, 255));

    black_image3 = dynamic_HUD2(black_image3);

    cv::imshow("Custom HUD", black_image);

    cv::imshow("Custom HUD Dynamic2", black_image3);
    cv::waitKey(0);
    return 0;
}