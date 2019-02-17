#include <iostream>
#include <algorithm>

using namespace std;

int sum[25][25];

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        string line;
        cin >> line;

        int n = line.length();

        for (int i = 0; i < n; i++) {
            if (i == 0)
                sum[0][i] = line[i] - '0';
            else
                sum[0][i] = (line[i] - '0') + sum[0][i-1];
        }

        for (int i = 1; i < n; i++) {
            cin >> line;
            for (int j = 0; j < n; j++) {
                if (j == 0)
                    sum[i][j] = (line[j] - '0') + sum[i-1][j];
                else
                    sum[i][j] = (line[j] - '0') + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            }
        }

        int area, max_area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = n-1; k >= i; k--) {
                    for (int l = n-1; l >= j; l--) {
                        int width = l - j + 1;
                        int height = k - i + 1;

                        if (width * height <= max_area) break;

                        if (i == 0 && j == 0)
                            area = sum[k][l];
                        else if (i == 0)
                            area = sum[k][l] - sum[k][j-1];
                        else if (j == 0)
                            area = sum[k][l] - sum[i-1][l];
                        else
                            area = sum[k][l] - sum[i-1][l] - sum[k][j-1] + sum[i-1][j-1];

                        if (area == width * height)
                            max_area = max(max_area, area);
                    }
                }
            }
        }

        cout << max_area << endl;

        if (T != 0)
            cout << endl;
    }
    return 0;
}