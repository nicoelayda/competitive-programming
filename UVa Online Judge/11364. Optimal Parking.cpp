#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int T, n;
    cin >> T;

    while (T-- != 0) {
        cin >> n;
        vector<int> shops(n, 0);

        for (int i = 0; i < n; i++) {
            cin >> shops[i];
        }

        sort(shops.begin(), shops.end());

        int dist = shops[n-1] - shops[0];

        for (int i = 0; i < n-1; i++) {
            dist += shops[i+1] - shops[i];
        }

        cout << dist << endl;
    }
    return 0;
}