#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        int size, blocks;
        cin >> size >> blocks;

        vector<vector<int> > board(size, vector<int>(size, 0));
        vector<vector<int> > sum(size, vector<int>(size, 0));

        while (blocks-- != 0) {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;

            for (int i = r1 - 1; i < r2; i++) {
                for (int j = c1 - 1; j < c2; j++) {
                    board[i][j] = 1;
                }
            }
        }

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == 0 && j == 0)
                    sum[i][j] = board[i][j];
                else if (i == 0)
                    sum[i][j] = board[i][j] + sum[i][j - 1];
                else if (j == 0)
                    sum[i][j] = board[i][j] + sum[i - 1][j];
                else
                    sum[i][j] = board[i][j] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
            }
        }

        int curr, largest = 0;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = i; k < size; k++) {
                    for (int l = j; l < size; l++) {
                        int height = k - i + 1;
                        int width = l - j + 1;

                        if (i == 0 && j == 0)
                            curr = sum[k][l];
                        else if (i == 0)
                            curr = sum[k][l] - sum[k][j - 1];
                        else if (j == 0)
                            curr = sum[k][l] - sum[i - 1][l];
                        else
                            curr = sum[k][l] - sum[i - 1][l] - sum[k][j - 1] + sum[i - 1][j - 1];


                        if (curr == 0)
                            largest = max(width * height, largest);
                    }
                }
            }
        }

        cout << largest << endl;
    }

    return 0;
}