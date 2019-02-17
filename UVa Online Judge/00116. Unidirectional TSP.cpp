#include <cstdio>
#include <algorithm>
#include <limits>

using namespace std;

int abs_mod(int a, int b) {
    return ((a % b) + b) % b;
}

int main() {
    int m, n;

    while (scanf("%d %d", &m, &n) == 2) {
        long long grid[m][n], dp[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%lld", &grid[i][j]);
                dp[i][j] = 0;
            }
        }

        int start = -1;
        long long min_path_cost = numeric_limits<long long>::max();
        
        // construct dp table
        for (int j = n - 1; j >= 0; j--) {
            for (int i = 0; i < m; i++) {
                if (j == n - 1) {
                    dp[i][j] = grid[i][j];
                }
                else {
                    dp[i][j] = grid[i][j] + min(dp[abs_mod(i-1, m)][j+1], min(dp[i][j+1], dp[abs_mod(i+1, m)][j+1]));
                }

                if (j == 0) {
                    if (dp[i][j] < min_path_cost) {
                        min_path_cost = dp[i][j];
                        start = i;
                    }
                }
            }
        }       

        // print start position
        printf("%d", start + 1);
        
        // rebuild cheapest path
        int curr_row, next_row = start;

        for (int j = 1; j < n; j++) {
            long long min_step = numeric_limits<long long>::max();
            curr_row = next_row;
            next_row = m;

            for (int i = -1; i <= 1; i++) {
                int tmp_row = abs_mod(curr_row + i, m);

                if (dp[tmp_row][j] == min_step && tmp_row < next_row) {
                    next_row = tmp_row;
                }
                else if (dp[tmp_row][j] < min_step) {
                    min_step = dp[tmp_row][j];
                    next_row = tmp_row;
                }
            }

            printf(" %d", next_row + 1);
        }

        printf("\n%lld\n", min_path_cost);
    }

    return 0;
}