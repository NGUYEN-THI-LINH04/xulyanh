/*#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>
#include <ctime>

using namespace cv;
using namespace std;

// =====================================================
// 1. THÊM NHIỄU GAUSSIAN
// =====================================================
Mat addGaussianNoise(Mat src, double mean = 0, double sigma = 20)
{
    Mat noise(src.size(), CV_32F);
    randn(noise, mean, sigma);

    Mat src_float;
    src.convertTo(src_float, CV_32F);

    Mat noisy = src_float + noise;

    threshold(noisy, noisy, 255, 255, THRESH_TRUNC);
    threshold(noisy, noisy, 0, 0, THRESH_TOZERO);

    noisy.convertTo(noisy, CV_8U);
    return noisy;
}

// =====================================================
// 2. THÊM NHIỄU SALT & PEPPER
// =====================================================
Mat addSaltPepperNoise(Mat src, double amount = 0.02)
{
    Mat noisy = src.clone();
    int numNoise = amount * src.total();

    for (int i = 0; i < numNoise; i++)
    {
        int x = rand() % src.cols;
        int y = rand() % src.rows;

        if (rand() % 2)
            noisy.at<uchar>(y, x) = 255;
        else
            noisy.at<uchar>(y, x) = 0;
    }

    return noisy;
}

// =====================================================
// 3. TÍNH MSE
// =====================================================
double calculateMSE(Mat original, Mat filtered)
{
    Mat diff;
    absdiff(original, filtered, diff);

    diff.convertTo(diff, CV_32F);
    diff = diff.mul(diff);

    return sum(diff)[0] / original.total();
}

// =====================================================
// 4. TÍNH PSNR
// =====================================================
double calculatePSNR(double mse)
{
    if (mse == 0) return 100;

    return 10.0 * log10((255 * 255) / mse);
}

// =====================================================
// FFT SHIFT
// =====================================================
void fftShift(Mat& img)
{
    int cx = img.cols / 2;
    int cy = img.rows / 2;

    Mat q0(img, Rect(0, 0, cx, cy));
    Mat q1(img, Rect(cx, 0, cx, cy));
    Mat q2(img, Rect(0, cy, cx, cy));
    Mat q3(img, Rect(cx, cy, cx, cy));

    Mat temp;

    q0.copyTo(temp);
    q3.copyTo(q0);
    temp.copyTo(q3);

    q1.copyTo(temp);
    q2.copyTo(q1);
    temp.copyTo(q2);
}

// =====================================================
// LỌC THÔNG THẤP FFT
// =====================================================
Mat lowPassFFT(Mat src, int radius)
{
    Mat padded;

    int m = getOptimalDFTSize(src.rows);
    int n = getOptimalDFTSize(src.cols);

    copyMakeBorder(src, padded, 0, m - src.rows, 0, n - src.cols,
        BORDER_CONSTANT, Scalar::all(0));

    padded.convertTo(padded, CV_32F);

    Mat planes[] = { padded, Mat::zeros(padded.size(), CV_32F) };
    Mat complexI;

    merge(planes, 2, complexI);

    dft(complexI, complexI);

    fftShift(complexI);

    Mat mask = Mat::zeros(padded.size(), CV_32F);
    Point center(mask.cols / 2, mask.rows / 2);

    for (int i = 0; i < mask.rows; i++)
    {
        for (int j = 0; j < mask.cols; j++)
        {
            double d = sqrt(pow(i - center.y, 2) + pow(j - center.x, 2));

            if (d <= radius)
                mask.at<float>(i, j) = 1;
        }
    }

    Mat mask2[] = { mask, mask };
    Mat complexMask;

    merge(mask2, 2, complexMask);

    mulSpectrums(complexI, complexMask, complexI, 0);

    fftShift(complexI);

    idft(complexI, complexI);

    split(complexI, planes);

    Mat result = planes[0];

    normalize(result, result, 0, 255, NORM_MINMAX);

    result.convertTo(result, CV_8U);

    return result(Rect(0, 0, src.cols, src.rows));
}

// =====================================================
// LỌC THÔNG CAO FFT
// =====================================================
Mat highPassFFT(Mat src, int radius)
{
    Mat padded;

    int m = getOptimalDFTSize(src.rows);
    int n = getOptimalDFTSize(src.cols);

    copyMakeBorder(src, padded, 0, m - src.rows, 0, n - src.cols,
        BORDER_CONSTANT, Scalar::all(0));

    padded.convertTo(padded, CV_32F);

    Mat planes[] = { padded, Mat::zeros(padded.size(), CV_32F) };
    Mat complexI;

    merge(planes, 2, complexI);

    dft(complexI, complexI);

    fftShift(complexI);

    Mat mask = Mat::ones(padded.size(), CV_32F);
    Point center(mask.cols / 2, mask.rows / 2);

    for (int i = 0; i < mask.rows; i++)
    {
        for (int j = 0; j < mask.cols; j++)
        {
            double d = sqrt(pow(i - center.y, 2) + pow(j - center.x, 2));

            if (d <= radius)
                mask.at<float>(i, j) = 0;
        }
    }

    Mat mask2[] = { mask, mask };
    Mat complexMask;

    merge(mask2, 2, complexMask);

    mulSpectrums(complexI, complexMask, complexI, 0);

    fftShift(complexI);

    idft(complexI, complexI);

    split(complexI, planes);

    Mat result = planes[0];

    normalize(result, result, 0, 255, NORM_MINMAX);

    result.convertTo(result, CV_8U);

    return result(Rect(0, 0, src.cols, src.rows));
}

// =====================================================
// MAIN
// =====================================================
int main()
{
    srand(time(0));

    Mat src = imread("D:/xulyanh/test4.jpg", IMREAD_GRAYSCALE);

    if (src.empty())
    {
        cout << "Khong mo duoc anh!" << endl;
        return -1;
    }

    // THÊM NHIỄU
    Mat gaussian = addGaussianNoise(src);
    Mat saltpepper = addSaltPepperNoise(src);

    // LỌC KHÔNG GIAN
    Mat mean_G, median_G;
    blur(gaussian, mean_G, Size(3, 3));
    medianBlur(gaussian, median_G, 3);

    Mat mean_SP, median_SP;
    blur(saltpepper, mean_SP, Size(3, 3));
    medianBlur(saltpepper, median_SP, 3);

    // LỌC FFT
    Mat low_G = lowPassFFT(gaussian, 30);
    Mat high_G = highPassFFT(gaussian, 30);

    Mat low_SP = lowPassFFT(saltpepper, 30);
    Mat high_SP = highPassFFT(saltpepper, 30);

    cout << "===== GAUSSIAN NOISE =====" << endl;

    double mse = calculateMSE(src, mean_G);
    cout << "Mean Filter: MSE = " << mse << " PSNR = " << calculatePSNR(mse) << endl;

    mse = calculateMSE(src, median_G);
    cout << "Median Filter: MSE = " << mse << " PSNR = " << calculatePSNR(mse) << endl;

    mse = calculateMSE(src, low_G);
    cout << "LowPass FFT: MSE = " << mse << " PSNR = " << calculatePSNR(mse) << endl;

    mse = calculateMSE(src, high_G);
    cout << "HighPass FFT: MSE = " << mse << " PSNR = " << calculatePSNR(mse) << endl;

    cout << "\n===== SALT & PEPPER NOISE =====" << endl;

    mse = calculateMSE(src, mean_SP);
    cout << "Mean Filter: MSE = " << mse << " PSNR = " << calculatePSNR(mse) << endl;

    mse = calculateMSE(src, median_SP);
    cout << "Median Filter: MSE = " << mse << " PSNR = " << calculatePSNR(mse) << endl;

    mse = calculateMSE(src, low_SP);
    cout << "LowPass FFT: MSE = " << mse << " PSNR = " << calculatePSNR(mse) << endl;

    mse = calculateMSE(src, high_SP);
    cout << "HighPass FFT: MSE = " << mse << " PSNR = " << calculatePSNR(mse) << endl;

    // HIỂN THỊ
    imshow("Original", src);
    imshow("Gaussian Noise", gaussian);
    imshow("SaltPepper Noise", saltpepper);

    imshow("Mean Gaussian", mean_G);
    imshow("Median Gaussian", median_G);
    imshow("LowPass Gaussian", low_G);
    imshow("HighPass Gaussian", high_G);

    imshow("Mean SaltPepper", mean_SP);
    imshow("Median SaltPepper", median_SP);
    imshow("LowPass SaltPepper", low_SP);
    imshow("HighPass SaltPepper", high_SP);

    waitKey(0);

    return 0;
}*/