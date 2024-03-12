#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/types.hpp>

using namespace cv;
int main()
{
    Mat img = imread("image.jpg", IMREAD_COLOR);
    if (img.empty()){
        std::cout << "Изображение не загружено" << std::endl;
        return -1;
    }

    Mat part1 = img(Rect(0, 0, img.cols / 2, img.rows / 2));
    Mat part2 = img(Rect(img.cols / 2, 0, img.cols / 2, img.rows / 2));
    Mat part3 = img(Rect(0, img.rows / 2, img.cols / 2, img.rows / 2));
    Mat part4 = img(Rect(img.cols / 2, img.rows / 2, img.cols / 2, img.rows / 2));
    imshow("Display window1", part1);
    imshow("Display window2", part2);
    imshow("Display window3", part3);
    imshow("Display window4", part4);

    Mat mask = Mat::zeros(img.size(), img.type());
    circle(mask, Point(img.cols / 2, img.rows / 2), 200, Scalar(255, 255, 255), -1);
    imshow("Mask", mask);
    Mat r = Mat::zeros(img.size(), img.type());

    // std::cout << img.size() << " " << r.rows << " " << r.cols << std::endl;

    bitwise_and(img, mask, r);
    for(int i = 0; i < r.rows; i++){
        for(int j = 0; j < r.cols; j++){
            if(!mask.at<uchar>(i, j)){
                r.at<uchar>(i, j) = 255;
            }
        }
    }
    imshow("Result", r);
    waitKey(0);
    return 0;
}
