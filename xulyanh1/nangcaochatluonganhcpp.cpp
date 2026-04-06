#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/*int main() {
    string path;
    int C;

    // Nhập đường dẫn ảnh
    cout << "Nhap duong dan anh mau: ";
    getline(cin, path);

    // Đọc ảnh màu
    Mat imgColor = imread(path, IMREAD_COLOR);
    if (imgColor.empty()) {
        cout << "Khong doc duoc anh!" << endl;
        return -1;
    }

    // Chuyển sang ảnh xám
    Mat imgGray;
    cvtColor(imgColor, imgGray, COLOR_BGR2GRAY);

    // Nhập hằng số C
    cout << "Nhap hang so C (tang do sang): ";
    cin >> C;

    // Tăng độ sáng
    Mat imgBright = imgGray.clone();
    for (int i = 0; i < imgGray.rows; i++) {
        for (int j = 0; j < imgGray.cols; j++) {
            int value = imgGray.at<uchar>(i, j) + C;
            imgBright.at<uchar>(i, j) = saturate_cast<uchar>(value);
        }
    }

    // Hiển thị kết quả
    imshow("Anh mau", imgColor);
    imshow("Anh xam", imgGray);
    imshow("Anh xam tang do sang", imgBright);

    waitKey(0);
    return 0;
}*/ 
