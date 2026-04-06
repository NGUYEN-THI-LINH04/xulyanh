#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

/*int main() {
    Mat img = imread("D:/xulyanh/test.jpg", IMREAD_GRAYSCALE);

    if (img.empty()) {
        cout << "Khong mo duoc anh!" << endl;
        return -1;
    }
    // In kích thước ảnh
    cout << "Kich thuoc anh: " << img.cols << " x " << img.rows << endl;

    // Hiển thị ảnh xám
    imshow("Anh xam", img);

    // Cắt vùng ảnh 10x10
    Mat region = img(Rect(0, 0, 10, 10));

    // Hiển thị vùng ảnh 10x10
    imshow("Vung anh 10x10", region);

    // In ma trận pixel 10x10
    cout << "Ma tran 10x10 dau tien:\n";
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << (int)region.at<uchar>(i, j) << "\t";
        }
        cout << endl;
    }
    waitKey(0);
    return 0;
}*/ 
