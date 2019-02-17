#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        vector<int> lands;
        int land;

        while (cin >> land && land != 0) {
            lands.push_back(land);
        }

        sort(lands.begin(), lands.end(), greater<int>());

        unsigned long long price = 0;
        for (int i = 0; i < lands.size(); i++) {
            price += 2 * pow(lands[i], i + 1);

            if (price > 5000000)
                break;
        }

        if (price > 5000000)
            cout << "Too expensive" << endl;
        else
            cout << price << endl;
    }
    return 0;
}