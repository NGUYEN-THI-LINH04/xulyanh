/*#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
    Mat img = imread("D:/xulyanh/test8.jpg");

    if (img.empty())
    {
        cout << "Khong mo duoc anh!" << endl;
        return -1;
    }

    Mat result = img.clone();

    // ===================================
    // 1. Tăng sáng & contrast nhẹ
    // ===================================
    result.convertTo(result, CV_8UC3, 1.08, 12);
    // alpha = 1.08 (contrast nhẹ)
    // beta = 12 (brightness vừa)

    // ===================================
    // 2. Chỉnh màu RGB nhẹ (giảm ám vàng)
    // ===================================
    vector<Mat> bgr;
    split(result, bgr);

    add(bgr[2], 4, bgr[2]);       // Red +
    add(bgr[1], 2, bgr[1]);       // Green +
    subtract(bgr[0], 2, bgr[0]);  // Blue -

    merge(bgr, result);

    // ===================================
    // 3. Tăng saturation rất nhẹ (màu trong hơn)
    // ===================================
    Mat hsv;
    cvtColor(result, hsv, COLOR_BGR2HSV);

    vector<Mat> hsvChannels;
    split(hsv, hsvChannels);

    hsvChannels[1].convertTo(hsvChannels[1], -1, 1.08, 0);

    merge(hsvChannels, hsv);
    cvtColor(hsv, result, COLOR_HSV2BGR);

    // ===================================
    // 4. Tăng nét nhẹ (Unsharp Mask)
    // ===================================
    Mat blur;
    GaussianBlur(result, blur, Size(0, 0), 1.5);

    addWeighted(result, 1.2, blur, -0.2, 0, result);

    // ===================================
    // 5. Resize hiển thị
    // ===================================
    Mat smallOriginal, smallResult;
    resize(img, smallOriginal, Size(), 0.5, 0.5);
    resize(result, smallResult, Size(), 0.5, 0.5);

    imshow("Anh goc", smallOriginal);
    imshow("Anh dep hon (tu nhien)", smallResult);

    waitKey(0);
    return 0;
}*/ 