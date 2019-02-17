#include <cstdio>

using namespace std;

int main() {
    int n, m;
    bool first = true;

    while (scanf("%d %d", &n, &m) == 2) {
        long long dp[n][n];

        if (first)
            first = false;
        else
            printf("\n");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int elem;
                scanf("%d", &elem);

                if (i == 0 && j == 0)
                    dp[i][j] = elem;
                else if (i == 0)
                    dp[i][j] = elem + dp[i][j - 1];
                else if (j == 0)
                    dp[i][j] = elem + dp[i - 1][j];
                else
                    dp[i][j] = elem + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            }
        }

        long long total_sum = 0;

        for (int i = 0; i + m - 1 < n; i++) {
            for (int j = 0; j + m - 1 < n; j++) {
                long long local_sum;

                if (i == 0 && j == 0)
                    local_sum = dp[i+m-1][j+m-1];
                else if (i == 0)
                    local_sum = dp[i+m-1][j+m-1] - dp[i+m-1][j-1];
                else if (j == 0)
                    local_sum = dp[i+m-1][j+m-1] - dp[i-1][j+m-1];
                else
                    local_sum = dp[i+m-1][j+m-1] - dp[i-1][j+m-1] - dp[i+m-1][j-1] + dp[i-1][j-1];

                total_sum += local_sum;
                printf("%ld\n", local_sum);
            }
        }

        printf("%ld\n", total_sum);
    }
    return 0;
}