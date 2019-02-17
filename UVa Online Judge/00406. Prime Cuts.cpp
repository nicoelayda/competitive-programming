#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<bool> is_prime(1001, true);

void sieve(int limit) {
    is_prime[0] = false;

    for (int i = 2; i*i <= limit; i++) {
        if (is_prime[i]) {
            for (int j = i*i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

vector<int> get_primes(int limit) {
    vector<int> primes;

    for (int i = 1; i <= limit; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

void print_primes(vector<int> primes, int c) {
    int lb, ub;

    if (primes.size() % 2 == 0) {
        lb = primes.size() / 2 - c;
        ub = primes.size() / 2 + (c - 1);
    }
    else {
        lb = primes.size() / 2 - (c - 1);
        ub = primes.size() / 2 + (c - 1);
    }
    
    lb = max(lb, 0);
    ub = min(ub, (int) (primes.size() - 1));

    for (int i = lb; i <= ub; i++) {
        cout << " " << primes[i];
    }

    cout << endl;
}

int main() {
    int n, c;
    sieve(1000);

    while (cin >> n >> c) {
        cout << n << " " << c << ":";
        print_primes(get_primes(n), c);
        cout << endl;
    }
    return 0;
}