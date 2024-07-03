#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include<stdio.h>

using namespace cv;
using namespace std;

void VeBieuDoHistogram(Mat img, String nameWindow)
{
	// Khoi tao gia tri
	int histSize = 256; // so luong pixel cho moi gia tri pixel(0 - 255)
		float range[] = { 0, 255 }; //Pham vi gia tri muon do
	const float* ranges[] = { range };
	// Tinh histogram
	MatND hist;
	calcHist(&img, 1, 0, Mat(), hist, 1, &histSize, ranges, true, false);
	int hist_w = 512; int hist_h = 400;
	int bin_w = cvRound((double)hist_w / histSize);
	// Truoc khi vẽ, chuẩn hóa kết quả về khoảng [0 ,Hist.rows]
	Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(0, 0,0));
	normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	// Vẽ biểu đồ Hist
	for (int i = 1; i < histSize; i++)
	{
		line(histImage, Point(bin_w * (i - 1), hist_h -
			cvRound(hist.at<float>(i - 1))),
			Point(bin_w * (i), hist_h - cvRound(hist.at<float>(i))),
			Scalar(255, 0, 0), 2, 8, 0);
	}
	imshow(nameWindow, histImage);
}
void Histogram(Mat img) {
	img = imread("ga.jpg", cv::IMREAD_GRAYSCALE);
	String namewindow = "Bieu do Hist truoc can bang";
	Mat imgDst(img.rows, img.cols, CV_8UC3);
	VeBieuDoHistogram(img, namewindow);
	equalizeHist(img, imgDst);
	imshow("Sau can bang Histogram", imgDst);
	String namewindow1 = "Bieu do Hist sau can bang";
	VeBieuDoHistogram(imgDst, namewindow1);
	waitKey(0);
}
