#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include<stdio.h>

using namespace cv;
using namespace std;
void USM(Mat in, long size, float a, float thresh) {
	in = imread("ga.jpg");
	size += (1 - (size % 2));
	Mat inF32;
	in.convertTo(inF32, CV_32FC1);
	Mat out;
	GaussianBlur(inF32, out, cv::Size(size, size), 0.0);
	Mat hp = inF32 - out;
	Mat hpabs = cv::abs(hp);
	Mat hpthr;
	threshold(hpabs, hpthr, thresh, 1.0, THRESH_BINARY);
	Mat ret1 = inF32 + a * hp.mul(hpthr);
	Mat ret;
	ret1.convertTo(ret, CV_8UC1);
	imshow("goc", in);
	imshow("Unsharp Mask", ret);
	waitKey(0);
}
