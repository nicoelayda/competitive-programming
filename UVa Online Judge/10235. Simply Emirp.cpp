#include <iostream>
#include <vector>

using namespace std;

const int LIMIT = 1000000;
vector<bool> is_prime(LIMIT + 1, true);

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
}

int reverse_int(int n) {
    int reverse = 0;

    while (n != 0) {
        reverse = reverse * 10 + n % 10;
        n /= 10;
    }

    return reverse;
}

int main() {
    int n;

    sieve(LIMIT);

    while (cin >> n) {
        int reverse = reverse_int(n);
        if (n != reverse && is_prime[n] && is_prime[reverse])
            cout << n << " is emirp." << endl;
        else if (is_prime[n])
            cout << n << " is prime." << endl;
        else
            cout << n << " is not prime." << endl;
    }
    return 0;
}