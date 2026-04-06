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

    // Ảnh kết quả
    Mat edge = Mat::zeros(img.size(), CV_32SC1);

    // Áp dụng Laplace theo đúng công thức
    for (int y = 1; y < img.rows - 1; y++)
    {
        for (int x = 1; x < img.cols - 1; x++)
        {
            edge.at<int>(y, x) =
                -img.at<uchar>(y - 1, x - 1)   // f(x-1,y-1)
                - img.at<uchar>(y - 1, x)       // f(x,  y-1)
                - img.at<uchar>(y - 1, x + 1)   // f(x+1,y-1)
                - img.at<uchar>(y, x - 1)   // f(x-1,y)
                - img.at<uchar>(y, x + 1)   // f(x+1,y)
                - img.at<uchar>(y + 1, x - 1)   // f(x-1,y+1)
                - img.at<uchar>(y + 1, x)       // f(x,  y+1)
                - img.at<uchar>(y + 1, x + 1)   // f(x+1,y+1)
                + 9 * img.at<uchar>(y, x);      // +9f(x,y)
        }
    }

    // Chuẩn hóa để hiển thị
    Mat edge_abs;
    convertScaleAbs(edge, edge_abs);

    imshow("Anh goc", img);
    imshow("Laplace Sharpen", edge_abs);

    waitKey(0);
    return 0;
}*/ 
