#include <iostream>

using namespace std;

int main() {
    int tc = 0;
    string str1, str2;

    while (getline(cin, str1) && str1[0] != '#' && getline(cin, str2)) {
        int lcs[str1.length() + 1][str2.length() + 1];

        for (int i = 0; i <= str1.length(); i++)
            lcs[i][0] = 0;

        for (int i = 0; i <= str2.length(); i++)
            lcs[0][i] = 0;

        for (int i = 1; i <= str1.length(); i++) {
            for (int j = 1; j <= str2.length(); j++) {
                if (str1[i - 1] == str2[j - 1])
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                else
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }

        cout << "Case #" << ++tc << ": you can visit at most "
             << lcs[str1.length()][str2.length()] << " cities." << endl;
    }

    return 0;
}