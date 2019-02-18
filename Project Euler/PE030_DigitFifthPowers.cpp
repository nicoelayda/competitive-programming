#include <iostream>
#include <cmath>

using namespace std;

const int limit = 6 * pow(9, 5);

int fifth_powers[10];

bool is_5th_power_sum(int n) {
    int num = n, sum = 0;

    while (num != 0) {
        sum += fifth_powers[num % 10];
        num /= 10;
    }

    return sum == n;
}

int main() {
    int limit;

    // fill table of 5th powers
    for (int i = 0; i < 10; i++) {
        fifth_powers[i] = pow(i, 5);
    }

    // compute for limit, the first multiple m of 9^5 with m digits.
    for (int i = 1; i != floor(log10(i * fifth_powers[9])) + 1; i++) { 
        limit = (i+1) * fifth_powers[9];
    }

    int sum = 0;
    for (int i = 2; i <= limit; i++) {
        if (is_5th_power_sum(i))
            sum += i;
    }

    cout << sum << endl;
    return 0;
}