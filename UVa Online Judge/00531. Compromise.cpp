#include <iostream>
#include <vector>

using namespace std;

int main() {
    string word;

    while (cin >> word) {
        vector<string> set1, set2;

        if (word != "#") {
            set1.push_back(word);

            while (cin >> word && word != "#") {
                set1.push_back(word);
            }
        }

        while (cin >> word && word != "#") {
            set2.push_back(word);
        }

        int lcs[set1.size() + 1][set2.size() + 1];

        for (int i = 0; i <= set1.size(); i++)
            lcs[i][0] = 0;

        for (int i = 0; i <= set2.size(); i++)
            lcs[0][i] = 0;

        for (int i = 1; i <= set1.size(); i++) {
            for (int j = 1; j <= set2.size(); j++) {
                if (set1[i - 1] == set2[j - 1])
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                else
                    lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
            }
        }

        int i = set1.size();
        int j = set2.size();

        vector<string> subsequence;

        while (i != 0 && j != 0) {
            if (set1[i - 1] == set2[j - 1]) {
                subsequence.insert(subsequence.begin(), set1[i - 1]);
                i--, j--;
            }
            else if (lcs[i][j] <= lcs[i][j - 1])
                j--;
            else
                i--;
        }

        for (int i = 0; i < subsequence.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << subsequence[i];
        }
        cout << endl;
    }

    return 0;
}