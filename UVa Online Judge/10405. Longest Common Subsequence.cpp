#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int lcs_length(string s1, string s2) {
    vector< vector<int> > dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));

    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    return dp[s1.length()][s2.length()];
}

int main() {
    string s1, s2;

    while (getline(cin, s1) && getline(cin, s2))
        cout << lcs_length(s1, s2) << endl;
    return 0;
}