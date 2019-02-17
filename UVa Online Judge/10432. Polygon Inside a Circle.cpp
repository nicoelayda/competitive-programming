#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

double polygon_area(double n, double r) {
    return n * r * r * sin(2 * M_PI / n) / 2;
}

int main() {
    double r, n;

    while (cin >> r >> n)
        printf("%.3lf\n", polygon_area(n, r));

    return 0;
}