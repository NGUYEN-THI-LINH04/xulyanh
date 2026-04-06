#include <stdio.h>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

/*int main()
{
	Mat A = imread("D:/xulyanh/test4.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat B;
	int width = 400, height = 400;
	int size = 256;
	float range[] = { 0, 255 };
	const float* HRange = { range };

	calcHist(&A, 1, 0, Mat(), B, 1, &size, &HRange, true, false);// tinh toan hinh dang cua bieu do

	int bin = cvRound((double)width / size);

	Mat LD(width, height, CV_8UC3, Scalar(255, 255, 255));

	normalize(B, B, 0, LD.rows, NORM_MINMAX, -1, Mat());

	for (int i = 0; i < 255; i++) {
		line(LD, Point(bin * (i), height), Point(bin * (i), height - cvRound(B.at<float>(i))), Scalar(0, 0, 0), 2, 8, 0);
	}

	imshow("hinh_goc", A);
	imshow("luoc_do_xam", LD);

	waitKey(0);

	return 0;
}*/ 