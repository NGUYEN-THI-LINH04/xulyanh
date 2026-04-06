#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

/*int main() {
    // Đọc ảnh màu (mặc định OpenCV đọc theo BGR)
    Mat img = imread("D:/xulyanh/test.jpg");

    if (img.empty()) {
        cout << "Khong mo duoc anh!" << endl;
        return -1;
    }
    // Hiển thị ảnh gốc
    imshow("Anh mau goc (BGR)", img);
    // Tách 3 kênh màu (theo thứ tự B - G - R)
    vector<Mat> channels;
    split(img, channels);
    Mat B = channels[0];   // Kênh Blue
    Mat G = channels[1];   // Kênh Green
    Mat R = channels[2];   // Kênh Red
    // Hiển thị từng kênh màu
    imshow("Kenh Blue", B);
    imshow("Kenh Green", G);
    imshow("Kenh Red", R);
    // Tạo ảnh mô hình RGB (BGR -> RGB để hiển thị đúng)
    Mat imgRGB;
    cvtColor(img, imgRGB, COLOR_BGR2RGB);
    imshow("Anh mau trong mo hinh RGB", imgRGB);
    waitKey(0);
    return 0;
}*/ 
