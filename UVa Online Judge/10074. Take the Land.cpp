#include <iostream>
#include <algorithm>

using namespace std;

int land[101][101];

int main() {
    int rows, cols, n;

    while (cin >> rows >> cols) {
        if (rows == 0 && cols == 0) break;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> n;

                if (i == 0 && j == 0)
                    land[i][j] = !n;
                else if (i == 0)
                    land[i][j] = !n + land[i][j - 1];
                else if (j == 0) 
                    land[i][j] = !n + land[i - 1][j];
                else
                    land[i][j] = !n + land[i][j - 1] + land[i - 1][j] - land[i - 1][j - 1];
            }
        }

        int area, max_area = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int k = rows - 1; k >= i; k--) {
                    for (int l = cols - 1; l >= j; l--) {
                        int width = l - j + 1;
                        int height = k - i + 1;

                        if (width * height <= max_area) break;  

                        if (i == 0 & j == 0)
                            area = land[k][l];
                        else if (i == 0)
                            area = land[k][l] - land[k][j - 1];
                        else if (j == 0)
                            area = land[k][l] - land[i - 1][l];
                        else
                            area = land[k][l] - land[i - 1][l] - land[k][j - 1] + land[i - 1][j - 1];

                        if (area == width * height)
                            max_area = max(area, max_area);
                    }
                }
            }
        }

        cout << max_area << endl;
    }
    return 0;
}