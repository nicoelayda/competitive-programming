#include <cstdio>
#include <numeric>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T-- != 0) {
        int num_coins;
        scanf("%d", &num_coins);

        // Handler for 0 coins
        if (num_coins == 0) {
            printf("0\n");
            continue;
        }
        
        // array of coins
        vector<int> coins = vector<int>(num_coins);

        // read from input
        for (int i = 0; i < num_coins; i++)
            scanf("%d", &coins[i]);

        // calculate max sum and first bag's limit
        int coin_sum = accumulate(coins.begin(), coins.end(), 0);
        int limit = coin_sum / 2;

        // init dp table to 0
        vector< vector<int> > dp(num_coins + 1, vector<int>(limit + 1, 0));

        // construct dp table
        for (int i = 1; i <= num_coins; i++) {
            for (int j = 0; j <= limit; j++) {
                if (coins[i - 1] <= j)
                    dp[i][j] = max(dp[i - 1][j], coins[i - 1] + dp[i - 1][j - coins[i - 1]]); // maximize
                else
                    dp[i][j] = dp[i - 1][j]; // copy
            }
        }
        
        int bag1_weight = dp[num_coins][limit];
        int bag2_weight = coin_sum - bag1_weight;

        printf("%d\n", bag2_weight - bag1_weight);
    }

    return 0;
}