#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

vector<bool> is_prime(101);
vector<int> primes;

void sieve(int limit) {
    fill(is_prime.begin(), is_prime.end(), true);
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i*i <= limit; i++) {
        if (is_prime[i]) {
            for (int j = i*i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= 100; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    int n, num;
    sieve(100);
    vector<int> factors(primes.size());

    while (scanf("%d", &n) == 1 && n != 0) {
        fill(factors.begin(), factors.end(), 0);
        
        for (int i = 2; i <= n; i++) {
            num = i;
            for (int j = 0; j < primes.size(); j++) {
                while (num % primes[j] == 0) {
                    factors[j]++;
                    num /= primes[j];
                }
            }
        }

        printf("%3d! =", n);
        for (int i = 0, printed = 0; i < factors.size() && factors[i] != 0; i++, printed++) {
            if (printed != 0 && printed % 15 == 0)
                printf("\n%6s", " ");
            printf("%3d", factors[i]);
        }
        printf("\n");
    }

    return 0;
}