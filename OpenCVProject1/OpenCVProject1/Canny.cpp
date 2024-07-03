#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include<stdio.h>

using namespace cv;
using namespace std;
void TachCanhCanny(Mat img){
	img = imread("aaa.jpg", cv::IMREAD_GRAYSCALE);
	imshow("Anh goc", img);
	Canny(img, img, 255 / 3, 255);
	imshow("Canny Filter", img);
	waitKey(0);
}
