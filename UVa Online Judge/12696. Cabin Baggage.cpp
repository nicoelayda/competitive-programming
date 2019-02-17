#include <cstdio>

using namespace std;

int main() {
    int T, allowed = 0;
    double l, w, d, sum, weight;
    scanf("%d", &T);

    while (T-- != 0) {
        scanf("%lf %lf %lf %lf", &l, &w, &d, &weight);
        sum = l + w + d;

        if (weight <= 7.0 && ((l <= 56.0 && w <= 45.0 && d <= 25.0) || (sum <= 125.0))) {
            printf("1\n");
            allowed++;
        }
        else
            printf("0\n");
    }
    printf("%d\n", allowed);
    return 0;
}