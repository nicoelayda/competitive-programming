#include <iostream>
#include <cmath>

using namespace std;

const double LOG2 = log10(2);

double log2(double num) {
    return log10(num) / LOG2;
}

int main() {
    int n, tc = 0;

    while (cin >> n && n >= 0) {
        cout << "Case " << ++tc << ": " << int(ceil(log2(n))) << endl;
    }

    return 0;
}