#include <iostream>
using namespace std;

// Hàm tích chập 3x3 (xếp chồng tại trung tâm)
/*int h2(int a[7][7], int x, int y)
{
    return a[x - 1][y - 1] + a[x - 1][y] + a[x - 1][y + 1]
        + a[x][y - 1] + a[x][y] + a[x][y + 1]
        + a[x + 1][y - 1] + a[x + 1][y] + a[x + 1][y + 1];
}

int main()
{
    // Ảnh gốc I (5x5)
    int I[5][5] = {
        {4, 7, 2, 7, 1},
        {5, 7, 1, 7, 1},
        {6, 6, 1, 8, 3},
        {5, 7, 5, 7, 1},
        {5, 7, 6, 1, 2}
    };

    // Padding ảnh thành 7x7 (viền 0)
    int I_pad[7][7] = { 0 };

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            I_pad[i + 1][j + 1] = I[i][j];

    // Ma trận kết quả Y (5x5)
    int Y[5][5] = { 0 };

    // Xếp chồng tại biên (tính cho mọi pixel)
    for (int m = 0; m < 5; m++)
    {
        for (int n = 0; n < 5; n++)
        {
            // +1 vì đã padding
            Y[m][n] = h2(I_pad, m + 1, n + 1);
        }
    }

    // In kết quả
    cout << "Ma tran Y (xep chong tai bien):\n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << Y[i][j] << "\t";
        cout << endl;
    }

    return 0;
}*/ 
