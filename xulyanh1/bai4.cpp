#include <iostream>
using namespace std;

// Hàm tích chập tại trung tâm (3x3)
/*int h2(int a[5][5], int x, int y)
{
    return a[x - 1][y - 1] + a[x - 1][y] + a[x - 1][y + 1]
        + a[x][y - 1] + a[x][y] + a[x][y + 1]
        + a[x + 1][y - 1] + a[x + 1][y] + a[x + 1][y + 1];
}

int main()
{
    // Ma trận ảnh gốc X (5x5)
    int X[5][5] = {
        {4, 7, 2, 7, 1},
        {5, 7, 1, 7, 1},
        {6, 6, 1, 8, 3},
        {5, 7, 5, 7, 1},
        {5, 7, 6, 1, 2}
    };

    // Ma trận kết quả Y (5x5), mặc định = 0
    int Y[5][5] = { 0 };

    // CHỈ tính tại trung tâm (m,n = 1..3 theo chỉ số mảng)
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            Y[i][j] = h2(X, i, j);
        }
    }

    // In kết quả
    cout << "Ma tran Y:\n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << Y[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}*/ 
