#include <opencv2/opencv.hpp> 
#include <iostream> 
#include <cmath> 

using namespace cv;
using namespace std;

Mat resizeToFitScreen(Mat img, int maxWidth = 1200, int maxHeight = 800)
{
    int width = img.cols;
    int height = img.rows;

    double scale = min((double)maxWidth / width, (double)maxHeight / height);

    if (scale < 1.0)
    {
        Mat resized;
        resize(img, resized, Size(), scale, scale);
        return resized;
    }

    return img;
}

int main()
{
    // ============================== 
    // 1. ĐỌC ẢNH 
    // ============================== 

    string imagePath = "D:/xulyanh/MEOMEO.jpg";
    Mat imgColor = imread(imagePath);

    if (imgColor.empty())
    {
        cout << "Khong the doc anh!" << endl;
        return -1;
    }

    // ============================== 
    // 2. CHUYỂN SANG ẢNH XÁM 
    // ============================== 

    Mat imgGray;
    cvtColor(imgColor, imgGray, COLOR_BGR2GRAY);

    // Resize ảnh để vừa màn hình 
    Mat imgColorShow = resizeToFitScreen(imgColor);
    Mat imgGrayShow = resizeToFitScreen(imgGray);

    imshow("Anh goc", imgColorShow);
    imshow("Anh xam", imgGrayShow);

    // ============================== 
    // 3. TÍNH HISTOGRAM 
    // ============================== 

    int histSize = 256;
    
        float range[] = { 0,256 };
    const float* histRange = { range };

    Mat hist;
    calcHist(&imgGray, 1, 0, Mat(), hist, 1, &histSize, &histRange);

    // ============================== 
    // 4. TÍNH ĐẶC TRƯNG THỐNG KÊ 
    // ============================== 

    double mean = 0;
    double variance = 0;
    double stddev = 0;
    double skewness = 0;
    double kurtosis = 0;

    int totalPixels = imgGray.rows * imgGray.cols;

    for (int i = 0; i < 256; i++)
        mean += i * hist.at<float>(i);

    mean /= totalPixels;

    for (int i = 0; i < 256; i++)
    {
        double diff = i - mean;
        double freq = hist.at<float>(i);

        variance += diff * diff * freq;
        skewness += pow(diff, 3) * freq;
        kurtosis += pow(diff, 4) * freq;
    }

    variance /= totalPixels;
    stddev = sqrt(variance);

    if (stddev != 0)
    {
        skewness /= (totalPixels * pow(stddev, 3));
        kurtosis /= (totalPixels * pow(stddev, 4));
    }

    // ============================== 
    // 5. HIỂN THỊ KẾT QUẢ 
    // ============================== 

    cout << "\n===== KET QUA PHAN TICH =====\n";
    cout << "Mean: " << mean << endl;
    cout << "Variance: " << variance << endl;
    cout << "Standard Deviation: " << stddev << endl;
    cout << "Skewness: " << skewness << endl;
    cout << "Kurtosis: " << kurtosis << endl;

    // ============================== 
    // 6. VẼ HISTOGRAM 
    // ============================== 

    int hist_w = 512;
    int hist_h = 400;
    int bin_w = cvRound((double)hist_w / histSize);

    Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));


        normalize(hist, hist, 0, histImage.rows, NORM_MINMAX);

    for (int i = 1; i < histSize; i++)
    {
        line(histImage,
            Point(bin_w * (i - 1), hist_h - cvRound(hist.at<float>(i - 1))),
            Point(bin_w * (i), hist_h - cvRound(hist.at<float>(i))),
            Scalar(0, 0, 0), 2);
    }

    imshow("Histogram", histImage);

    waitKey(0);
    destroyAllWindows();

    return 0;
}