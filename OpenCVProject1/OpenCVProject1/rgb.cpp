#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include<stdio.h>

using namespace cv;
using namespace std;

void splitRGB(cv::Mat img )
{
	Mat rgb[3];
	split(img, rgb);
	imshow("Original", img);
	imshow("blue", rgb[0]);
	imshow("red", rgb[2]);
	imshow("green", rgb[1]);

	imwrite("blue.jpg", rgb[0]);
	imwrite("green.jpg", rgb[1]);
	imwrite("red.jpg", rgb[2]);
	waitKey(0);
}