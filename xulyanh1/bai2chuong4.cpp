#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/*int main() {
    string path;
    int C;

    // Nhập đường dẫn ảnh màu
    cout << "Nhap duong dan anh mau: ";
    getline(cin, path);

    // Đọc ảnh màu
    Mat imgColor = imread(path, IMREAD_COLOR);
    if (imgColor.empty()) {
        cout << "Khong doc duoc anh!" << endl;
        return -1;
    }

    // Nhập hằng số C
    cout << "Nhap hang so C: ";
    cin >> C;

    // Tăng độ sáng ảnh màu
    Mat imgBright = imgColor.clone();
    for (int i = 0; i < imgColor.rows; i++) {
        for (int j = 0; j < imgColor.cols; j++) {
            for (int k = 0; k < 3; k++) {  // B, G, R
                int value = imgColor.at<Vec3b>(i, j)[k] + C;
                imgBright.at<Vec3b>(i, j)[k] = saturate_cast<uchar>(value);
            }
        }
    }

    // Hiển thị kết quả
    imshow("Anh mau goc", imgColor);
    imshow("Anh mau tang do sang", imgBright);

    waitKey(0);
    return 0;
}*/ 
