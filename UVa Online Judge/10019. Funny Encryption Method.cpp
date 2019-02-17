#include <cstdio>
#include <cmath>

using namespace std;

int count_ones(int n) {
    if (n == 0 || n == 1)
        return n;
    return count_ones(n >> 1) + (n % 2 == 0 ? 0 : 1);
}

int hex_to_dec(int n) {
    int dec = 0, e = 0;

    while (n != 0) {
        dec += (n % 10) * pow(16, e++);
        n /= 10;
    }

    return dec;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T-- != 0) {
        int m;
        scanf("%d", &m);
        printf("%d %d\n", count_ones(m), count_ones(hex_to_dec(m)));
    }
}