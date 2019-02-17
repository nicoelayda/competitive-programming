#include <cmath>
#include <cstdio>

using namespace std;

double area_triangle(double m1, double m2, double m3) {
    double ss = (m1 + m2 + m3) / 2;
    return 4 * sqrt(ss * (ss - m1) * (ss - m2) * (ss - m3)) / 3;
}

int main() {
    double m1, m2, m3;

    while (scanf("%lf %lf %lf", &m1, &m2, &m3) == 3) {
        double area = area_triangle(m1, m2, m3);
        
        if (area > 0)
            printf("%.3lf\n", area);
        else
            printf("%.3lf\n", -1.0);
    }

    return 0;
}