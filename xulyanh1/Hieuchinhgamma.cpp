#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>

using namespace cv;
using namespace std;

/*int main()
{
    string path;     // đường dẫn ảnh
    double C, gamma; // hằng số C và gamma

    // ===============================
    // 1. NHẬP ĐƯỜNG DẪN ẢNH
    // ===============================
    cout << "Nhap duong dan anh mau: ";
    getline(cin, path);

    // Đọc ảnh màu
    Mat img = imread(path, IMREAD_COLOR);

    // Kiểm tra lỗi
    if (img.empty())
    {
        cout << "Khong mo duoc anh!" << endl;
        return -1;
    }

    // ===============================
    // 2. NHẬP C VÀ GAMMA
    // ===============================
    cout << "Nhap hang so C: ";
    cin >> C;
    cout << "Nhap gamma: ";
    cin >> gamma;

    // Ảnh kết quả
    Mat result = img.clone();

    // ===============================
    // 3. HIỆU CHỈNH GAMMA
    // I'(x,y) = C * [I(x,y)]^gamma
    // ===============================
    for (int i = 0; i < img.rows; i++)
    {
        for (int j = 0; j < img.cols; j++)
        {
            for (int k = 0; k < 3; k++) // B, G, R
            {
                // Chuẩn hóa pixel về [0,1]
                double p = img.at<Vec3b>(i, j)[k] / 255.0;

                // Áp dụng công thức gamma
                double value = C * pow(p, gamma) * 255.0;

                // Giới hạn trong [0,255]
                if (value > 255) value = 255;
                if (value < 0)   value = 0;

                result.at<Vec3b>(i, j)[k] = (uchar)value;
            }
        }
    }

    // ===============================
    // 4. HIỂN THỊ KẾT QUẢ
    // ===============================
    imshow("Anh goc", img);
    imshow("Anh hieu chinh Gamma", result);

    waitKey(0);
    return 0;
}*/ 
