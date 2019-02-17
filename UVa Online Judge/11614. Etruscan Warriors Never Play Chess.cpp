#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        unsigned long long n;
        cin >> n;

        cout << ((unsigned long long) ((sqrt(8 * n + 1) - 1) / 2)) << endl;
    }
    return 0;
}