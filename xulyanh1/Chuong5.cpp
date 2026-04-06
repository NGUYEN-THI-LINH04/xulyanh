#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/*int main() {
    // Đọc ảnh
    Mat img = imread("D:/xulyanh/test.jpg");
    if (img.empty()) {
        cout << "Khong mo duoc anh!" << endl;
        return -1;
    }

    // Chuyển sang ảnh xám
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);

    // Ảnh biên
    Mat edge = Mat::zeros(gray.size(), CV_8UC1);

    int delta = 20; // ngưỡng δ1

    // Duyệt ảnh
    for (int i = 1; i < gray.rows - 1; i++) {
        for (int j = 1; j < gray.cols - 1; j++) {

            int sum = 0;
            for (int ii = i - 1; ii <= i + 1; ii++) {
                for (int jj = j - 1; jj <= j + 1; jj++) {
                    sum += gray.at<uchar>(ii, jj);
                }
            }

            int avg = sum / 9;
            int fxy = gray.at<uchar>(i, j);

            if (abs(fxy - avg) > delta)
                edge.at<uchar>(i, j) = 255;
            else
                edge.at<uchar>(i, j) = 0;
        }
    }

    // Hiển thị
    imshow("Anh goc", img);
    imshow("Anh xam", gray);
    imshow("Anh bien cuc bo", edge);

    waitKey(0);
    return 0;
}*/ 
