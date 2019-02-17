#include <iostream>

using namespace std;

unsigned long long slices(unsigned long long cuts) {
    return cuts * (cuts + 1) / 2 + 1;
}

int main() {
    long long n;

    while (cin >> n && n >= 0) {
        cout << slices(n) << endl;
    }

    return 0;
}   