#include <iostream>
using namespace std;

/*int main() {
    int I[7][6] = {
        {3,5,7,6,9,1},
        {5,7,6,9,1,3},
        {7,6,9,1,3,5},
        {6,9,1,3,5,7},
        {9,1,3,5,7,6},
        {1,3,5,7,6,9},
        {3,5,7,6,9,1}
    };

    int g[6] = { 1,3,5,6,7,9 };
    int h[6] = { 0 };
    int t[6] = { 0 };
    int f[6] = { 0 };

    int M = 7, N = 6;
    int new_level = 6;
    int TB = (M * N) / new_level;

    // Tính histogram
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 6; j++)
            for (int k = 0; k < 6; k++)
                if (I[i][j] == g[k])
                    h[k]++;

    // Tính t(g) tích lũy
    t[0] = h[0];
    for (int i = 1; i < 6; i++)
        t[i] = t[i - 1] + h[i];

    // Tính f(g)
    for (int i = 0; i < 6; i++) {
        f[i] = t[i] / TB - 1;
        if (f[i] < 0) f[i] = 0;
    }

    // In bảng kết quả
    cout << "g\t h(g)\t t(g)\t f(g)\n";
    for (int i = 0; i < 6; i++)
        cout << g[i] << "\t " << h[i] << "\t " << t[i] << "\t " << f[i] << endl;

    return 0;
}*/ 
