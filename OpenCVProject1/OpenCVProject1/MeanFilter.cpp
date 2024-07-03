#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include<stdio.h>

using namespace cv;
using namespace std;

void meanFilter(cv:: Mat img) {
	img = imread("ga.jpg", cv::IMREAD_GRAYSCALE);
	int sizeMatrix = 9;
	Mat dst = img.clone();
	for (int y = 0; y < img.rows; y++) {
		for (int x = 0; x < img.cols; x++) {
			dst.at<uchar>(y, x) = 0.0;
			double mean = 0.0;
			for (int y = 1; y < img.rows - 1; y++) {
				for (int x = 1; x < img.cols - 1; x++) {
					mean = (img.at<uchar>(y - 1, x - 1)
						+ img.at<uchar>(y, x - 1)
						+ img.at<uchar>(y + 1, x - 1)
						+ img.at<uchar>(y - 1, x)
						+ img.at<uchar>(y, x)
						+ img.at<uchar>(y + 1, x)
						+ img.at<uchar>(y - 1, x + 1)
						+ img.at<uchar>(y, x + 1)
						+ img.at<uchar>(y + 1, x + 1)) /sizeMatrix;
						dst.at<uchar>(y, x) = mean;
				}
			}
		}
	}
	imshow("Anh goc", img);
	imshow("Sau Mean Filter", dst);
	waitKey();
}