//
//  main.cpp
//  test
//
//  Created by 徐亦燊 on 2020/2/28.
//  Copyright © 2020 徐亦燊. All rights reserved.
//


#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;

int main( )
{
   
    Mat src = imread("/Users/xuyishen/Desktop/sa jiganyouhaximeiyouga/2020.4.10/2/1.png");
    Mat dst;
    Canny(src, dst, 50, 200, 3);
    std::vector<cv::Vec2f> lines;
    HoughLines(dst, lines, 1, CV_PI/180, 100 );
    std::vector<cv::Vec2f>::iterator it = lines.begin();
    for (; it != lines.end(); ++it)
    {
        float rho = (*it)[0], theta = (*it)[1];
        cv::Point pt1, pt2;
        double a = cos(theta), b = sin(theta);
        double x0 = a * rho, y0 = b * rho;
        pt1.x = cv::saturate_cast<int>(x0 + 1000 * (-b));
        pt1.y = cv::saturate_cast<int>(y0 + 1000 * (a));
        pt2.x = cv::saturate_cast<int>(x0 - 1000 * (-b));
        pt2.y = cv::saturate_cast<int>(y0 - 1000 * (a));
        cv::line(src, pt1, pt2, cv::Scalar(0, 0, 255),1, LINE_AA);
    }
    imshow("src", src);
    imshow("dst", dst);
    waitKey(0);
    return 0;
}


