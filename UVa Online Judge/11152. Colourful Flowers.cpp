#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

double t_area(double s1, double s2, double s3) {
    double k = (s1 + s2 + s3) / 2.0;

    return sqrt(k * (k-s1) * (k-s2) * (k-s3));
}

int main() {
    int a, b, c;

    while (cin >> a >> b >> c) {
        double violets = t_area(a, b, c);
        double sunflowers = pow(1.0 * (a * b * c) / (4 * violets), 2) * M_PI - violets;
        double roses = pow(violets / (1.0 * (a + b + c) / 2), 2) * M_PI;

        violets -= roses;

        printf("%.4lf %.4lf %.4lf\n", sunflowers, violets, roses);
    }
    return 0;
}