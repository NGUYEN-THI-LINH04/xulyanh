#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int ROW = 8;
const int COL = 8;

/*/ Hàm in ma trận
void printMatrix(string title, int a[ROW][COL]) {
    cout << title << endl;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    // Ma trận ảnh gốc I
    int I[ROW][COL] = {
        {0,0,0,0,0,0,0,0},
        {0,1,4,2,8,5,7,0},
        {0,4,2,8,5,7,1,0},
        {0,2,8,5,7,1,4,0},
        {0,8,5,7,1,4,2,0},
        {0,5,7,1,4,2,8,0},
        {0,7,1,4,2,8,5,0},
        {0,0,0,0,0,0,0,0}
    };

    int median[ROW][COL] = { 0 };
    int result[ROW][COL];

    // Copy I sang result ban đầu
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            result[i][j] = I[i][j];

    // Lọc trung vị 3x3
    for (int i = 1; i < ROW - 1; i++) {
        for (int j = 1; j < COL - 1; j++) {
            vector<int> window;

            for (int m = -1; m <= 1; m++) {
                for (int n = -1; n <= 1; n++) {
                    window.push_back(I[i + m][j + n]);
                }
            }

            sort(window.begin(), window.end());
            median[i][j] = window[4]; // phần tử trung vị
        }
    }

    // Lọc trung vị với ngưỡng theta
    int theta = 3;
    for (int i = 1; i < ROW - 1; i++) {
        for (int j = 1; j < COL - 1; j++) {
            if (abs(I[i][j] - median[i][j]) > theta) {
                result[i][j] = median[i][j];
            }
        }
    }

    // Hiển thị kết quả
    printMatrix("Ma tran anh goc I:", I);
    printMatrix("Ma tran loc trung vi:", median);
    printMatrix("Loc trung vi voi theta = 3:", result);

    return 0;
}*/ 
