#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        double d, v, u;
        cin >> d >> v >> u;

        if (v >= u || v == 0 || u == 0) {
            cout << "Case " << tc << ": can't determine" << endl;
        }
        else {
            double shortest = d / sqrt(u*u - v*v);
            double fastest = d / u;

            printf("Case %d: %.3lf\n", tc, shortest - fastest);
        }
    }

    return 0;
}