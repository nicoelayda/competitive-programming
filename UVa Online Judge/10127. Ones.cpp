#include <iostream>

using namespace std;

int main() {
    int n;

    while (cin >> n) {
        int digits = 1;
        int num = 1;

        while (num % n != 0) {
            num = (num * 10 + 1) % n;
            digits++;
        }

        cout << digits << endl;
    }

    return 0;
}