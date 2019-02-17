#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, event;
    cin >> n;

    vector<int> events(n);

    for (int i = 1; i <= n; i++) {
        cin >> event;
        events[event - 1] = i;
    }

    while (cin >> event) {
        vector<int> seq(n);
        seq[event - 1] = 1;

        for (int i = 2; i <= n; i++) {
            cin >> event;
            seq[event - 1] = i;
        }

        int lcs[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            lcs[0][i] = 0;
            lcs[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (events[i - 1] == seq[j - 1])
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                else
                    lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
            }
        }

        cout << lcs[n][n] << endl;
    }
    return 0;
}