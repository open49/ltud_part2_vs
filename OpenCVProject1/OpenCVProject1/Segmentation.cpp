#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include<stdio.h>

using namespace cv;
using namespace std;
void Segmentation(Mat img) {

	img = imread("ga.jpg");
	Mat img_gray(img.rows, img.cols, CV_8UC1);
	cvtColor(img, img_gray, COLOR_BGR2GRAY);
	Mat binary(img.rows, img.cols, CV_8UC1);
	threshold(img_gray, binary, 40, 255, THRESH_BINARY | THRESH_OTSU);

	Mat fg;
	erode(binary, fg, Mat(), Point(-1, -1), 2);

	Mat bg;
	dilate(binary, bg, Mat(), Point(-1, -1), 3);
	threshold(bg, bg, 1, 128, THRESH_BINARY_INV);

	Mat markers(binary.size(), CV_8U, Scalar(0));
	markers = fg + bg;
	markers.convertTo(markers, CV_32S);
	watershed(img, markers);
	markers.convertTo(markers, CV_8U);
	threshold(markers, markers, 40, 255, THRESH_BINARY | THRESH_OTSU);

	imshow("Org", img);
	imshow("Sau Segmentation", markers);

	waitKey();
}