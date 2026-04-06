#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

// Hàm vẽ histogram
Mat drawHistogram(int h[]) {
    int width = 400, height = 400;
    Mat histImg(height, width, CV_8UC3, Scalar(255, 255, 255));

    int maxVal = 0;
    for (int i = 0; i < 256; i++)
        if (h[i] > maxVal) maxVal = h[i];

    for (int i = 0; i < 256; i++) {
        int val = (double)h[i] / maxVal * height;
        line(histImg,
            Point(i * width / 256, height),
            Point(i * width / 256, height - val),
            Scalar(0, 0, 0), 1);
    }
    return histImg;
}

/*int main() {

    Mat img = imread("D:/xulyanh/test4.jpg", IMREAD_GRAYSCALE);
    if (img.empty()) {
        cout << "Khong mo duoc anh!" << endl;
        return -1;
    }

    int rows = img.rows;
    int cols = img.cols;
    int new_level = 20;

    int h[256] = { 0 }, h2[256] = { 0 };
    int t[256] = { 0 }, f[256] = { 0 };

    // Histogram gốc
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            h[img.at<uchar>(i, j)]++;

    int TB = (rows * cols) / new_level;

    // t(g)
    t[0] = h[0];
    for (int i = 1; i < 256; i++)
        t[i] = t[i - 1] + h[i];

    // f(g)
    for (int i = 0; i < 256; i++) {
        f[i] = t[i] / TB - 1;
        if (f[i] < 0) f[i] = 0;
        if (f[i] >= new_level) f[i] = new_level - 1;
    }

    // Ảnh sau cân bằng
    Mat result = img.clone();
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result.at<uchar>(i, j) =
            f[img.at<uchar>(i, j)] * (255 / (new_level - 1));

    // Histogram sau cân bằng
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            h2[result.at<uchar>(i, j)]++;

    // Vẽ histogram
    Mat histBefore = drawHistogram(h);
    Mat histAfter = drawHistogram(h2);

    imshow("Anh xam goc", img);
    imshow("Luoc do xam goc", histBefore);
    imshow("Anh sau can bang", result);
    imshow("Luoc do xam can bang", histAfter);

    waitKey(0);
    return 0;
}*/ 
