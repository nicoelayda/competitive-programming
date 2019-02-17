#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        long long num;
        cin >> num;
        cout << abs(((num * 567 / 9 + 7492) * 235 / 47 - 498) / 10 % 10) << endl;
    }
    return 0;
}