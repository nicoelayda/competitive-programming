#include <iostream>
#include <cmath>
#include <utility>
#include <vector>

using namespace std;

bool is_int(double n) {
    return n == floor(n);
}

int main() {
    int k;
    while (cin >> k) {
        vector<pair<int, int> > pairs;
        
        for (int y = k + 1; y <= 2 * k; y++) {
            double x = 0;
            if (y - k != 0)
                x = (1.0 * k * y) / (y - k);

            if (is_int(x) && x >= y)
                pairs.push_back(make_pair(x, y));
        }

        cout << pairs.size() << endl;
        for (int i = 0; i < pairs.size(); i++) {
            cout << "1/" << k << " = 1/" << pairs[i].first << " + " << "1/" << pairs[i].second << endl;
        }
    }

    return 0;
}