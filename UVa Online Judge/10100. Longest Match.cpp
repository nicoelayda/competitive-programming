#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

vector<string> tokenize(string str) {
    string word = string();
    vector<string> words;

    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i]) || isdigit(str[i])) {
            word += str[i];

            if (i == str.length() - 1)
                words.push_back(word);
        }
        else if (word.length() != 0) {
            words.push_back(word);
            word = string();
        }
        
    }

    return words;
}

int main() {
    int tc = 0;
    string s1, s2;

    while (getline(cin, s1) && getline(cin, s2)) {
        if (s1.length() == 0 || s2.length() == 0) {
            printf("%2d. Blank!\n", ++tc);
            continue;
        }

        vector<string> words1 = tokenize(s1);
        vector<string> words2 = tokenize(s2);

        int dp[words1.size() + 1][words2.size() + 1];

        for (int i = 0; i <= words1.size(); i++) dp[i][0] = 0;
        for (int i = 0; i <= words2.size(); i++) dp[0][i] = 0;

        for (int i = 1; i <= words1.size(); i++) {
            for (int j = 1; j <= words2.size(); j++) {
                if (words1[i - 1] == words2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        printf("%2d. Length of longest match: %d\n", ++tc, dp[words1.size()][words2.size()]);
    }
    return 0;
}