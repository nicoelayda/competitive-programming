#include <iostream>
#include <cstring>

using namespace std;

string alphabet = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
bool is_prime[1041];

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

int value_of(char ch) {
    for (int i = 1; i <= alphabet.length(); i++) {
        if (alphabet[i] == ch)
            return i;
    }

    return 0;
}

int main() {
    string word;

    memset(is_prime, true, sizeof(is_prime));
    sieve(value_of('Z') * 20);

    while (cin >> word) {
        int sum = 0;
        for (int i = 0; i < word.length(); i++)
            sum += value_of(word[i]);

        if (is_prime[sum])
            cout << "It is a prime word." << endl;
        else
            cout << "It is not a prime word." << endl;
    }

    return 0;
}