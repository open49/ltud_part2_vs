#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include<stdio.h>
#include "function.h"

using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("ga.jpg", IMREAD_COLOR);
	


	//inanh();
	//splitRGB(img);
	//imgYUV(img);
	//Histogram(img);
	//medianFilter(img);
	//meanFilter(img);
	//TachCanhSobel(img);
	//TachCanhCanny(img);
	DCT(img);
	//GaussianFilter(img);
	//USM(img, 10, 10, 10);
	//Segmentation(img);
	return 0;
}
