#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include<stdio.h>

using namespace cv;
using namespace std;

void imgYUV(cv::Mat img)
{
	Mat rgb[3];
	Mat y(img.rows, img.cols, CV_8UC1);
	Mat u(img.rows, img.cols, CV_8UC1);
	Mat v(img.rows, img.cols, CV_8UC1);
	split(img, rgb);
	int R, G, B, Y, U, V;
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			R = rgb[2].at<uchar>(i, j);
			G = rgb[1].at<uchar>(i, j);
			B = rgb[0].at<uchar>(i, j);
			Y = 0.299 * R + 0.587 * G + 0.114 * B;
			U = 128 - 0.168736 * R - 0.331264 * G + 0.5 * B;
			V = 128 + 0.5 * R - 0.418688 * G - 0.081312 * B;
			y.at<uchar>(i, j) = Y;
			u.at<uchar>(i, j) = U;
			v.at<uchar>(i, j) = V;
		}
	}
	imshow("V", v);
	imshow("U", u);
	imshow("Y", y);

	waitKey(0);
}