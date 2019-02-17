#include <cstdio>
#include <cstring>

using namespace std;

unsigned long long mod_pow(unsigned long long b, int e, int m) {
    unsigned long long result = 1;

    while (e > 0) {
        if (e % 2 == 1)
            result = (result * b) % m;

        e = e >> 1;
        b = (b * b) % m;
    }
    return result;
}

int main() {
    char n[256];
    int last[100];
    
    last[0] = 0;

    for (int i = 1; i < 100; i++)
        last[i] = (last[i-1] + mod_pow(i, i, 10)) % 10;

    while (scanf("%s", n) == 1 && n[0] != '0') {
        int digits = strlen(n);
        int tens_digit = digits == 1 ? 0 : n[digits - 2] - '0';
        int ones_digit = n[digits - 1] - '0';

        printf("%d\n", last[10 * tens_digit + ones_digit]);
    }
    
    return 0;
}