#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/*int main()
{
    Mat img = imread("D:/xulyanh/test4.jpg", IMREAD_GRAYSCALE);
    if (img.empty())
    {
        cout << "Khong doc duoc anh!" << endl;
        waitKey(0);
        return -1;
    }

    // Chuyển sang float
    Mat data;
    img.convertTo(data, CV_32F);

    // PCA = KL
    int K = 50;
    PCA pca(data, Mat(), PCA::DATA_AS_ROW, K);

    // Nén & tái tạo
    Mat reduced = pca.project(data);
    Mat reconstructed = pca.backProject(reduced);

    // Chuyển về uchar
    Mat result;
    reconstructed.convertTo(result, CV_8U);

    // Hiển thị
    imshow("Anh Goc", img);
    imshow("Anh Ket Qua", result);

    waitKey(0);
    destroyAllWindows();
    return 0;
}*/ 
