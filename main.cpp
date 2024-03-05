#include <iostream>
#include <string>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
int main()
{
    Mat img = imread("image.jpg", IMREAD_COLOR);
    if (img.empty()){
        std::cout << "Изображение не загружено" << std::endl;
        return -1;
    }
    MatSize s = img.size;
    std::string text = "Size: " + std::to_string(s.p[0]) + " x " + std::to_string(s.p[1]);
    putText(img, text, Point(0, 30), 0, 1.0, Scalar(255, 255, 255), 2);
    line(img, Point(200, 200), Point(400, 200), Scalar(0, 255, 0), 4);
    rectangle(img, Point(200, 1000), Point(400, 1200), Scalar(255, 25, 255), -1);
    rectangle(img, Point(1000, 1000), Point(1200, 1200), Scalar(0, 0, 255), 6);
    circle(img, Point(800, 800), 100, Scalar(0, 0, 255), 4);
    circle(img, Point(1200, 200), 100, Scalar(0, 125, 0), -1);
    namedWindow("Display window", WINDOW_NORMAL);
    imshow("Display window", img);
    waitKey(0);
    return 0;
}
