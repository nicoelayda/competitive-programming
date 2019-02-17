#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int LIMIT = 1 << 16;
vector<bool> is_prime(LIMIT + 1);

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
}

int modular_pow(unsigned long long base, int exp, int mod) {
    unsigned long long total = 1;
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            total = (total * base) % mod;
        }

        exp = exp >> 1;
        base = (base * base) % mod;
    }

    return total;
}

bool carmichael(int n) {
    if (is_prime[n])
        return false;

    for (int i = 2; i < n; i++) {
        if (modular_pow(i, n, n) != i) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    sieve(LIMIT);

    while (cin >> n && n != 0) {
        if (carmichael(n))
            cout << "The number " << n << " is a Carmichael number." << endl;
        else
            cout << n << " is normal." << endl;
    }
    return 0;
}