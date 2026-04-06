#include <opencv2/opencv.hpp>
#include <iostream>
#include <iomanip>   // ⭐ thêm dòng này

using namespace cv;
using namespace std;

/*int main() {
    Mat I = (Mat_<int>(8, 8) <<
        1, 1, 1, 1, 1, 1, 20, 15,
        1, 1, 1, 1, 1, 20, 15, 1,
        1, 1, 1, 1, 20, 15, 1, 1,
        1, 1, 1, 20, 15, 1, 1, 1,
        1, 1, 20, 15, 1, 1, 1, 1,
        1, 20, 15, 1, 1, 1, 1, 1,
        20, 15, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1
        );

    Mat H1 = (Mat_<int>(3, 3) <<
        -1, -1, -1,
        -1, 9, -1,
        -1, -1, -1
        );

    Mat Y = Mat::zeros(I.size(), CV_32S);

    // KHÔNG TÍNH BIÊN
    for (int x = 1; x < I.rows - 1; x++) {
        for (int y = 1; y < I.cols - 1; y++) {
            int sum = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    sum += I.at<int>(x + i, y + j) *
                        H1.at<int>(i + 1, j + 1);
                }
            }
            Y.at<int>(x, y) = sum;
        }
    }

    // ⭐ IN KẾT QUẢ ĐẸP
    cout << "Ma tran Y :\n";
    for (int i = 0; i < Y.rows; i++) {
        for (int j = 0; j < Y.cols; j++) {
            cout << setw(5) << Y.at<int>(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
}*/ 
