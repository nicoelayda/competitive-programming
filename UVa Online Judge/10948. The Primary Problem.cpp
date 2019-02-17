#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int LIMIT = 1000000;
vector<bool> is_prime(LIMIT + 1);
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
    
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i])
            primes.push_back(i);
    }
    
}

int main() {
    int n, diff;
    sieve(LIMIT);
    
    while (cin >> n && n != 0) {
        bool goldbach = false;
        
        cout << n << ":" << endl;
        for (int i = 0; i < primes.size() && primes[i] < n; i++) {
            if (is_prime[diff = n - primes[i]]) {
                cout << primes[i] << "+" << diff << endl;
                goldbach = true;
                break;
            }
        }    

        if (!goldbach)
            cout << "NO WAY!" << endl;
    }

    return 0;
}