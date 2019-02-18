#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int size_p = 100;

vector<int> primes;
bool is_prime[size_p + 1];

void sieve(int limit) {
    memset(is_prime, true, sizeof(bool) * (size_p + 1));
    
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i*i <= limit; i++){
        if (is_prime[i]) {
            for (int j = i*i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= limit; i++){
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

int p_index(int n) {
    int index = find(primes.begin(), primes.end(), n) - primes.begin();
    if (index < primes.size())
        return index;
    return -1;
}

int count_factors(unsigned long long n) {
    if (n == 0 || n == 1) return 1;

    int prime_factors[primes.size()];
    memset(prime_factors, 0, sizeof(int) * primes.size());

    int p = 0;
    while ((n > size_p || !is_prime[n]) && p < primes.size()) {
        if (n % primes[p] == 0) {
            n /= primes[p];
            prime_factors[p]++;
        }
        else {
            p++;
        }
    }

    prime_factors[p_index(n)]++;

    int factors = 1;
    for (int i = 0; i < primes.size(); i++) {
        if (prime_factors[i] != 0)
            factors *= (prime_factors[i] + 1);
    }

    return factors;

}

int main() {
    unsigned long long sum = 0;

    sieve(size_p);
    for (int i = 1; count_factors(sum) < 500; i++)
        sum += i;

    cout << sum << endl;
    return 0;    
}