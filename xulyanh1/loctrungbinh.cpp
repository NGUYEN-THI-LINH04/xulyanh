#include <iostream>
#include <cmath>
using namespace std;

const int ROW = 8;
const int COL = 8;

/*void printMatrix(const string& title, int a[ROW][COL]) {
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
    // Ảnh I
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

    int TB[ROW][COL] = { 0 };
    int KQ[ROW][COL];

    // copy I → KQ
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            KQ[i][j] = I[i][j];

    // TÍNH TB(p) – ROUND giống ảnh mẫu
    for (int i = 1; i < ROW - 1; i++) {
        for (int j = 1; j < COL - 1; j++) {
            int sum = 0;
            for (int m = -1; m <= 1; m++)
                for (int n = -1; n <= 1; n++)
                    sum += I[i + m][j + n];

            TB[i][j] = (sum + 4) / 9;   // ← DÒNG QUYẾT ĐỊNH
        }
    }


    // Áp dụng theta = 3
    int theta = 3;
    for (int i = 1; i < ROW - 1; i++) {
        for (int j = 1; j < COL - 1; j++) {
            if (abs(I[i][j] - TB[i][j]) > theta) {
                KQ[i][j] = TB[i][j];
            }
        }
    }

    printMatrix("Anh I:", I);
    printMatrix("TB(p):", TB);
    printMatrix("Anh KQ (theta = 3):", KQ);

    return 0;
}*/ 
