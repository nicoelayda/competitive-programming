#include <iostream>
#include <cstring>

using namespace std;

bool is_amicable[10000];
int sums[10000];

int sum_of_proper_divisors(int n) {
    if (n <= 1) return 0;

    if (sums[n] == 0) {
        sums[n] = 1;
        for (int i = 2; i*i <= n; i++) {
            if (n % i == 0) {
                sums[n] += i;
                if (i != n/i)
                    sums[n] += n / i;
            }
        }    
    }

    return sums[n];
}

int main() {
    memset(is_amicable, false, sizeof(bool) * 10000);
    memset(sums, 0, sizeof(int) * 10000);

    for (int i = 1; i < 9999; i++) {
        for (int j = i+1; j < 10000; j++) {
            if (sum_of_proper_divisors(i) == j && sum_of_proper_divisors(j) == i) {
                is_amicable[i] = true;
                is_amicable[j] = true;
            }
        }
    }

    int sum = 0;
    for (int i = 1; i < 10000; i++) {
        if (is_amicable[i])
            sum += i;
    }

    cout << sum << endl;
    return 0;
}