#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 1000000;

vector<int> primes;
vector<unsigned long long> sums;
bool is_prime[MAX + 1];

void sieve(int limit) {
    memset(is_prime, true, sizeof(bool) * (MAX + 1));

    for (int i = 2; i*i <= limit; i++) {
        if (is_prime[i]) {
            for (int j = i*i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }

    unsigned long long running_sum = 0;
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            sums.push_back(running_sum += i);
        }
    }
}

int main() {
    int max_len = 0;
    unsigned long long curr_sum, max_sum = 0;
    
    sieve(MAX);
    
    for (int i = 0; i < primes.size(); i++) {
        for (int j = i + max_len; j < primes.size(); j++) {
            curr_sum = sums[j] - (i == 0 ? 0 : sums[i-1]);

            if (curr_sum > MAX) break;

            int curr_len = j - i + 1;
            if (is_prime[curr_sum] && curr_len >= max_len) {
                max_len = curr_len;
                max_sum = curr_sum;
            }   
        }
    }

    cout << "n = " << max_sum << endl;
    return 0;
}