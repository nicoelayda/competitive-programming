#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double triangle_area(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p-a) * (p-b) * (p-c));
}

double triangle_angle(double a, double b, double c) {
    return acos((a*a + b*b - c*c) / (2*a*b));
}

double circle_area(double radians, double radius) {
    return (radians / 2) * radius * radius;
}

int main() {
    int k;
    double r1, r2, r3;
    cin >> k;

    while (k-- != 0) {
        cin >> r1 >> r2 >> r3;

        double a = r1 + r2;
        double b = r1 + r3;
        double c = r2 + r3;

        double angle_a = triangle_angle(b, c, a);
        double angle_b = triangle_angle(a, c, b);
        double angle_c = triangle_angle(a, b, c);

        double c1 = circle_area(angle_c, r1);
        double c2 = circle_area(angle_b, r2);
        double c3 = circle_area(angle_a, r3);

        double area_t = triangle_area(a, b, c);

        printf("%.6f\n", area_t - (c1 + c2 + c3));
    }

    return 0;
}