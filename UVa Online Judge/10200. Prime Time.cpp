#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int LIMIT = 10000;
vector<bool> is_prime(LIMIT + 1, true);
vector<int> primes;

void sieve(int limit) {
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i*i <= limit; i++) {
        if (is_prime[i]) {
            for (int j = i*i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= limit; i++) {
        primes.push_back(i);
    }
}

bool prime_check(int n) {
    if (n <= LIMIT)
        return is_prime[n];

    for (int i = 0; primes[i] * primes[i] <= n; i++) {
        if (n % primes[i] == 0)
            return false;
    }    

    return true;
}

int main() {
    int a, b;
    sieve(LIMIT);

    vector<int> prime_count(10001);
    prime_count[0] = 1;

    for (int i = 1; i <= 10000; i++) {
        if (prime_check(i*i + i + 41))
            prime_count[i] = prime_count[i - 1] + 1;
        else
            prime_count[i] = prime_count[i - 1];
    }

    while (cin >> a >> b) {
        int primes_found;
        if (a != 0)
            primes_found = prime_count[b] - prime_count[a - 1];
        else
            primes_found = prime_count[b];

        printf("%.2lf\n", 100.0 * primes_found / (b - a + 1) + 1e-9);
    }


    return 0;
}