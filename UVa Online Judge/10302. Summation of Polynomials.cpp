#include <iostream>

using namespace std;

int main() {
    int x;

    while (cin >> x) {
        long long sum = 0;
        for (long long i = 1; i <= x; i++)
            sum += i*i*i;

        cout << sum << endl;
    }
    return 0;
}