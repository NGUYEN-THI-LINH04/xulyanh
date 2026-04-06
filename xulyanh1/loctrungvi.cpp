#include <iostream>
using namespace std;

// Hàm tính trung vị của mảng
/*int trungvi(int a[], int n)
{
    int tg;
    // Sắp xếp tăng dần
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
            {
                tg = a[i];
                a[i] = a[j];
                a[j] = tg;
            }

    // Trả về trung vị
    return a[n / 2];
}

int main()
{
    // Ma trận ảnh gốc 8x8
    int I[8][8] = {
        {0,0,0,0,0,0,0,0},
        {0,1,4,2,8,5,7,0},
        {0,4,2,8,5,7,1,0},
        {0,2,8,5,7,1,4,0},
        {0,8,5,7,1,4,2,0},
        {0,5,7,1,4,2,8,0},
        {0,7,1,4,2,8,5,0},
        {0,0,0,0,0,0,0,0}
    };

    // Ma trận sau lọc trung vị (khởi tạo toàn 0)
    int I_trungvi[8][8] = { 0 };

    // Lọc trung vị 3x3 (chỉ xử lý vùng trong)
    for (int i = 1; i < 7; i++)
    {
        for (int j = 1; j < 7; j++)
        {
            int a[9], k = 0;

            for (int x = -1; x <= 1; x++)
                for (int y = -1; y <= 1; y++)
                    a[k++] = I[i + x][j + y];

            I_trungvi[i][j] = trungvi(a, 9);
        }
    }

    // In ma trận kết quả (có biên = 0)
    cout << "Ma tran trung vi:\n";
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            cout << I_trungvi[i][j] << " ";
        cout << endl;
    }

    return 0;
}*/ 