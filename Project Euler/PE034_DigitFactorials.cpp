#include <iostream>
#include <cmath>

using namespace std;

int fact[10];

bool digit_factorial(int n) {
    int fact_sum = 0;
    int num = n;

    while (num != 0) {
        fact_sum += fact[num % 10];
        num /= 10;
    }

    return fact_sum == n;
}

int main() {
    fact[0] = 1;
    fact[1] = 1;

    for (int i = 2; i <= 9; i++) {
        fact[i] = fact[i-1] * i;
    }

    int limit = fact[9];
    for (int i = 1; i != floor(log10(limit)) + 1; i++) {
        limit = i * fact[9];
    }

    int sum = 0;
    for (int i = 3; i <= limit; i++) {
        if (digit_factorial(i)) {
            sum += i;
        }
    }

    cout << sum << endl;
    return 0;
}