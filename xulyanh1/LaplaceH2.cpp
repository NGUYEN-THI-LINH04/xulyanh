#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/*int main()
{
    Mat img = imread("D:/xulyanh/test5.jpg", IMREAD_GRAYSCALE);
    if (img.empty())
    {
        cout << "Khong mo duoc anh!" << endl;
        return -1;
    }

    Mat edge = Mat::zeros(img.size(), CV_32SC1);

    for (int y = 1; y < img.rows - 1; y++)
    {
        for (int x = 1; x < img.cols - 1; x++)
        {
            edge.at<int>(y, x) =
                img.at<uchar>(y - 1, x - 1) +
                img.at<uchar>(y - 1, x) +
                img.at<uchar>(y - 1, x + 1) +
                img.at<uchar>(y, x - 1) +
                img.at<uchar>(y, x + 1) +
                img.at<uchar>(y + 1, x - 1) +
                img.at<uchar>(y + 1, x) +
                img.at<uchar>(y + 1, x + 1)
                - 8 * img.at<uchar>(y, x);
        }
    }

    Mat edge_abs;
    convertScaleAbs(edge, edge_abs);

    imshow("Anh goc", img);
    imshow("Laplace 8 huong", edge_abs);

    waitKey(0);
    return 0;
}*/ 
