#include <iostream>
#include <cstring>

using namespace std;

bool is_prime[2001];
int frequency[256];

void sieve(int limit) {
    memset(is_prime, true, sizeof(is_prime));
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

int main() {
    int cases;
    string line;
    sieve(2000);

    cin >> cases;

    for (int c = 1; c <= cases; c++) {
        cin >> line;
        memset(frequency, 0, sizeof(frequency));

        for (int i = 0; i < line.length(); i++) {
            frequency[line[i]]++;
        }

        bool empty = true;
        cout << "Case " << c << ": ";

        for (int i = 0; i < 256; i++) {
            if (is_prime[frequency[i]]) {
                empty = false;
                cout << ((char) i);
            }
        }

        if (empty) cout << "empty";
        cout << endl;
    }
    return 0;
}