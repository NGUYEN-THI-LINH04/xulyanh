#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/*int main() {

    // 1. Đọc ảnh
    Mat img = imread("D:/xulyanh/test.jpg");
    if (img.empty()) {
        cout << "Khong the mo anh!" << endl;
        return -1;
    }

    // 2. Thu nhỏ ảnh gốc để hiển thị
    Mat img_show;
    resize(img, img_show, Size(), 0.5, 0.5);

    // 3. Chuyển sang ảnh xám
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);

    // 4. Tách mã tứ phân (4 mức xám)
    Mat quat = gray.clone();
    uchar value[4] = { 32, 96, 160, 224 };

    for (int r = 0; r < gray.rows; r++) {
        uchar* pg = gray.ptr<uchar>(r);
        uchar* pq = quat.ptr<uchar>(r);

        for (int c = 0; c < gray.cols; c++) {
            int idx = pg[c] / 64;   // 0–3
            pq[c] = value[idx];
        }
    }

    // 5. Hiển thị kết quả
    imshow("Anh goc", img_show);
    imshow("Anh xam", gray);
    imshow("Anh ma tu phan", quat);

    waitKey(0);
    return 0;
}*/ 
