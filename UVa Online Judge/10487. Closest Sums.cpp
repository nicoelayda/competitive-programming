#include <iostream>
#include <limits>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m, tc = 0;

    while (cin >> n && n != 0) {
        vector<int> ints = vector<int>(n);

        for (int i = 0; i < n; i++)
            cin >> ints[i];

        vector<int> sums;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                sums.push_back(ints[i] + ints[j]);
            }
        }

        cout << "Case " << ++tc << ":" << endl;
        
        cin >> m;
        for (int i = 0; i < m; i++) {
            int query, closest_sum;
            int diff = numeric_limits<int>::max();
            
            cin >> query;

            for (int j = 0; j < sums.size(); j++) {
                if (abs(query - sums[j]) < diff) {
                    diff = abs(query - sums[j]);
                    closest_sum = sums[j];
                }
            }

            cout << "Closest sum to " << query << " is " << closest_sum  << "." << endl;
        }


    }
    return 0;
}