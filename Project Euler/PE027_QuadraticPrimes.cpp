#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

const int MAX = 16384;

std::vector<bool> is_prime(MAX + 1);

void sieve(int limit) {
    std::fill(is_prime.begin(), is_prime.end(), true);

    is_prime[0] = false;
    is_prime[1] = false;
    
    for (int i = 0; i*i <= limit; i++) {
        if (is_prime[i]){
            for (int j = i*i; j <= limit; j += i) {
                is_prime[j] = false;
            }       
        }
    }
}

int main() {
    int max = 0;
    int max_product = 0;
    
    sieve(MAX);

    for (int a = -999; a <= 999; a++) {
        for (int b = -999, n = 0; b <= 999; b++, n = 0) {
            while (is_prime[abs(n*n + a*n + b)])
                n++;

            if (n > max) {
                max = n;
                max_product = a * b;
            }
        }
    }

    std::cout << max_product << std::endl;
    return 0;
}