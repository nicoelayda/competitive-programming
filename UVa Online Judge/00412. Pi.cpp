#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int size;
    while (cin >> size && size != 0) {
        int numbers[size];

        for (int i = 0; i < size; i++) {
            cin >> numbers[i];
        }

        int pairs = 0;
        int relative_primes = 0;
        for (int i = 0; i < size-1; i++) {
            for (int j = i+1; j < size; j++) {
                pairs++;
                if (gcd(numbers[i], numbers[j]) == 1) {
                    relative_primes++;
                }
            }
        }

        if (relative_primes == 0) {
            cout << "No estimate for this data set." << endl;
        }
        else {
            printf("%.6lf\n", sqrt(6.0 * pairs / relative_primes));
        }
    }
    return 0;
}