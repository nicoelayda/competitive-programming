#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int m, n, t;

    while (cin >> m >> n >> t) {
        vector<int> dp(10010, -1);
        dp[0] = 0;
        dp[m] = 1;
        dp[n] = 1;

        //cout << m << " " << n << " " << t << endl;

        for (int i = min(m, n); i <= t; i++) {
            if (dp[i] != -1) {
                if (i + m <= t)
                    dp[i + m] = max(dp[i + m], dp[i] + 1);

                if (i + n <= t)
                    dp[i + n] = max(dp[i + n], dp[i] + 1);
            }
        }

        if (dp[t] != -1)
            cout << dp[t] << endl;
        else {
            int k = t - 1;
            while (dp[k] == -1)
                k--;
            cout << dp[k] << " " << (t - k) << endl;
        }
    }

    return 0;
}