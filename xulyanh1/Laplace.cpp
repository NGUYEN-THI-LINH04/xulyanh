#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/*int main()
{
    // Đọc ảnh xám
    Mat img = imread("D:/xulyanh/test5.jpg", IMREAD_GRAYSCALE);
    if (img.empty())
    {
        cout << "Khong mo duoc anh!" << endl;
        return -1;
    }

    // Ảnh lưu kết quả Laplace
    Mat edge = Mat::zeros(img.size(), CV_32SC1);

    int rows = img.rows;
    int cols = img.cols;

    // Áp dụng Laplace theo ĐÚNG công thức:
    // ∇²f(x,y) = f(x+1,y) + f(x−1,y) + f(x,y+1) + f(x,y−1) − 4f(x,y)
    for (int y = 1; y < rows - 1; y++)
    {
        for (int x = 1; x < cols - 1; x++)
        {
            edge.at<int>(y, x) =
                img.at<uchar>(y, x + 1) +  // f(x+1, y)
                img.at<uchar>(y, x - 1) +  // f(x-1, y)
                img.at<uchar>(y + 1, x) +  // f(x, y+1)
                img.at<uchar>(y - 1, x)    // f(x, y-1)
                - 4 * img.at<uchar>(y, x); // -4f(x, y)
        }
    }

    // Lấy trị tuyệt đối để hiển thị
    Mat edge_abs, edge_8u;
    convertScaleAbs(edge, edge_abs);
    edge_abs.convertTo(edge_8u, CV_8U);

    // Hiển thị kết quả
    imshow("Anh goc", img);
    imshow("Phat hien bien Laplace", edge_8u);

    waitKey(0);
    return 0;
}*/ 
