#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, cases;
    double digits;

    cin >> cases;

    while (cases-- != 0) {
        cin >> n;

        digits = 0;
        for (int i = 2; i <= n; i++)
            digits += log10(i);

        cout << ((int) digits + 1) << endl;
    }

    return 0;
}