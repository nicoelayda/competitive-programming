#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

double dist(int x, int y) {
    return sqrt(x * x + y * y);
}

int main() {
    int T, x, y, r;
    cin >> T;

    while (T-- != 0) {
        cin >> x >> y >> r;

        double d = dist(x, y);
        printf("%.2lf %.2lf\n", abs(d - r), abs(d + r));
    }

    return 0;
}