#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    int num_camps, num_days;

    while (cin >> num_camps >> num_days) {
        num_camps += 1;
        num_days += 1;

        vector<int> camps(num_camps);
        vector< vector<int> > dp(num_days, vector<int>(num_camps, INF));

        for (int i = 0; i < num_camps; i++) {
            cin >> camps[i];

            if (i != 0) 
                camps[i] += camps[i - 1];

            dp[0][i] = camps[i]; // base case
        }

        for (int i = 1; i < num_days; i++) {
            for (int j = 0; j < num_camps; j++) {
                for (int k = i - 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][k], camps[j] - camps[k]));
                }
            }
        }

        cout << dp[num_days - 1][num_camps - 1] << endl;
    }

    return 0;
}