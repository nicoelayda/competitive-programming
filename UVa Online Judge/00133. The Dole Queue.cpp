#include <iostream>
#include <list>
#include <iterator>
#include <cstdio>

using namespace std;

int circular_mod(int a, int b) {
    return ((a % b) + b) % b;
}

int main() {
    int n, k, m;

    while (cin >> n >> k >> m) {
        if (n == 0 && k == 0 && m == 0) break;

        list<int> dole;

        for (int i = 0; i < n; i++)
            dole.push_back(i + 1);

        int next_ccw = 0, next_cw = n;

        while (!dole.empty()) {
            next_ccw = (next_ccw + k - 1) % dole.size();
            next_cw = circular_mod(next_cw - m, dole.size());

            list<int>::iterator ccw_it = dole.begin();
            list<int>::iterator cw_it = dole.begin();

            advance(ccw_it, next_ccw);
            advance(cw_it, next_cw);

            if (*ccw_it == *cw_it) {
                printf("%3d", *ccw_it);
                dole.erase(ccw_it);
            }
            else {
                printf("%3d%3d", *ccw_it, *cw_it);

                if (*ccw_it > *cw_it) 
                    next_ccw--;
                else 
                    next_cw--;

                dole.erase(ccw_it);
                dole.erase(cw_it);
            }

            if (!dole.empty()) cout << ",";
        }

        cout << endl;
    }

    return 0;
}