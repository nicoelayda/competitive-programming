#include <iostream>
#include <climits>

using namespace std;

int size, num;
int sum[101][101];

int main() {
    while (cin >> size) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cin >> num;

                if (i == 0 && j == 0)
                    sum[i][j] = num;
                else if (i == 0)
                    sum[i][j] = num + sum[i][j - 1];
                else if (j == 0)
                    sum[i][j] = num + sum[i - 1][j];
                else
                    sum[i][j] = num + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
            }
        }

        int curr_sum, max_sum = INT_MIN;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = i; k < size; k++) {
                    for (int l = j; l < size; l++) {
                        
                        if (i == 0 && j == 0)
                            curr_sum = sum[k][l];
                        else if (i == 0)
                            curr_sum = sum[k][l] - sum[k][j - 1];
                        else if (j == 0)
                            curr_sum = sum[k][l] - sum[i - 1][l];
                        else
                            curr_sum = sum[k][l] - sum[i - 1][l] - sum[k][j - 1] + sum[i - 1][j - 1];

                        max_sum = max(curr_sum, max_sum);
                    }
                }
            }
        }

        cout << max_sum << endl;
    }
    return 0;
}