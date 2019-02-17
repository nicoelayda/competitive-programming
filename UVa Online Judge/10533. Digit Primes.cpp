#include <cstdio>
#include <algorithm>

using namespace std;

bool is_prime[1000001];
int digit_primes[1000000];

void sieve(int limit) {
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 0; i*i <= limit; i++) {
        if (is_prime[i]) {
            for (int j = i*i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

bool digit_prime(int n) {
    int sum = 0;
    int num = n;

    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    
    return is_prime[sum] && is_prime[num];
}

int main() {
    int n, t1, t2;

    fill(is_prime, is_prime + sizeof(is_prime)/sizeof(bool), true);
    fill(digit_primes, digit_primes + sizeof(digit_primes)/sizeof(int), 0);
    sieve(1000000);
    
    for (int i = 1; i < 1000000; i++) {
        digit_primes[i] += digit_primes[i-1] + (digit_prime(i) ? 1 : 0);
    }

    scanf("%d", &n);

    while (n-- != 0) {
        scanf("%d %d", &t1, &t2);
        printf("%d\n", digit_primes[t2] - digit_primes[t1-1]);
    }

    return 0;
}