#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int rows, cols, money;
        cin >> rows >> cols >> money;

        vector<vector<int> > dp(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int cell_cost;
                cin >> cell_cost;

                if (i == 0 && j == 0)
                    dp[i][j] = cell_cost;
                else if (i == 0)
                    dp[i][j] = cell_cost + dp[i][j - 1];
                else if (j == 0)
                    dp[i][j] = cell_cost + dp[i - 1][j];
                else
                    dp[i][j] = cell_cost + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
            }
        }

        int max_area = 0;
        int min_cost = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int k = rows - 1; k >= i; k--) {
                    for (int l = cols - 1; l >= j; l--) {
                        int height = k - i + 1;
                        int width = l - j + 1;

                        int area = width * height;

                        if (area < max_area) break;

                        int cost;
                        if (i == 0 && j == 0)
                            cost = dp[k][l];
                        else if (i == 0)
                            cost = dp[k][l] - dp[k][j - 1];
                        else if (j == 0)
                            cost = dp[k][l] - dp[i - 1][l];
                        else
                            cost = dp[k][l] - dp[k][j - 1] - dp[i - 1][l] + dp[i - 1][j - 1];

                        if (cost <= money) {
                            if (area > max_area) {
                                max_area = area;
                                min_cost = cost;
                            }
                            else if (area == max_area && cost < min_cost) {
                                min_cost = cost;
                            }
                        }
                    }
                }
            }
        }

        cout << "Case #" << tc << ": " << max_area << " " << min_cost << endl;
    }
    return 0;
}