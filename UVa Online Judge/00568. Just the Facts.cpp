#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const int last_digit[10] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};

int last_factorial_digit(int n) {
    if (n >= 0 && n <= 9) {
        return last_digit[n];
    }
    else {
        int tens = (n % 100) / 10;
        if (tens % 2 != 0)
            return (4 * last_factorial_digit(floor(n / 5.0)) * last_factorial_digit(n % 10)) % 10;
        else
            return (6 * last_factorial_digit(floor(n / 5.0)) * last_factorial_digit(n % 10)) % 10;
    }
}

int main() {
    int n;
    while (cin >> n) {
        printf("%5d -> %d\n", n, last_factorial_digit(n));
    }
    
    return 0;
}