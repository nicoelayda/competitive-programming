#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int num_inhabitants;

    while (cin >> num_inhabitants && num_inhabitants != 0) {

        int inhabitants[num_inhabitants];
        for (int i = 0; i < num_inhabitants; i++)
            cin >> inhabitants[i];

        long long cost = 0;

        for (int bi = 0, si = 0; bi < num_inhabitants; bi++) {
            while (inhabitants[bi] > 0) {
                while (inhabitants[si] >= 0) {
                    si++;
                }

                int transferred = min(abs(inhabitants[bi]), abs(inhabitants[si]));
                
                cost += transferred * abs(bi - si);
                inhabitants[bi] -= transferred;
                inhabitants[si] += transferred;
            }
        }

        cout << cost << endl;
    }

    return 0;
}