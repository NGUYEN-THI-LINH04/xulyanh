#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/*int main() {
    string path;

    // Nhập đường dẫn ảnh từ bàn phím
    cout << "Nhap duong dan anh mau: ";
    getline(cin, path);

    // Đọc ảnh màu
    Mat color = imread(path, IMREAD_COLOR);

    if (color.empty()) {
        cout << "Khong mo duoc anh!" << endl;
        return -1;
    }

    int rows = color.rows;
    int cols = color.cols;

    Mat gray(rows, cols, CV_8UC1);
    Mat binary(rows, cols, CV_8UC1);

    int T = 128;

    // Duyệt từng điểm ảnh
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Vec3b pixel = color.at<Vec3b>(i, j);

            uchar B = pixel[0];
            uchar G = pixel[1];
            uchar R = pixel[2];

            // Chuyển sang ảnh xám
            uchar grayValue = (uchar)(0.299 * R + 0.587 * G + 0.114 * B);
            gray.at<uchar>(i, j) = grayValue;

            // Chuyển sang ảnh nhị phân
            binary.at<uchar>(i, j) = (grayValue >= T) ? 255 : 0;
        }
    }

    imshow("Anh mau", color);
    imshow("Anh xam", gray);
    imshow("Anh nhi phan", binary);

    waitKey(0);
    return 0;
}*/ 
