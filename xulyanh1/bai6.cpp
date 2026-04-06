#include<stdio.h>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <cmath>

using namespace cv;
using namespace std;

/*int h3(Mat a, int x, int y)
{
    return
        a.at<uchar>(x - 1, y - 1) +
        2 * a.at<uchar>(x - 1, y) +
        a.at<uchar>(x - 1, y + 1) +

        2 * a.at<uchar>(x, y - 1) +
        4 * a.at<uchar>(x, y)  +
        2 * a.at<uchar>(x, y + 1) +

        a.at<uchar>(x + 1, y - 1) +
        2 * a.at<uchar>(x + 1, y) +
        a.at<uchar>(x + 1, y + 1);
}

int main()
{
    Mat A = imread("D:/xulyanh/test.jpg", CV_LOAD_IMAGE_GRAYSCALE);
    Mat B = A.clone();

    if (!A.data)
    {
        printf("Khong tim thay anh!");
        return -1;
    }

    B.setTo(0);

    int GtTb = 0;
    int TheTa = 3;

    for (int i = 1; i < A.rows - 1; i++)
    {
        for (int j = 1; j < A.cols - 1; j++)
        {
            GtTb = h3(A, i, j);
            GtTb = round(GtTb / 16.0);  // kernel H2

            if ((A.at<uchar>(i, j) - GtTb) < TheTa)
                B.at<uchar>(i, j) = A.at<uchar>(i, j);
            else
                B.at<uchar>(i, j) = GtTb;
        }
    }

    imshow("Anh goc", A);
    imshow("Anh ket qua", B);
    waitKey(0);
    return 0;
}*/ 
