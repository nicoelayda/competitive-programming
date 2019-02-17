#include <iostream>
#include <sstream>

using namespace std;

int main() {
    int n, m;

    while (cin >> n >> m) {
        stringstream ss;
        ss << n;

        if (n < m || n < 2 || m < 2) {
            cout << "Boring!" << endl;
            continue;
        }

        while (n != 1 && n % m == 0 & m != 1)
            ss << " " << (n /= m);

        if (n == 1)
            cout << ss.str() << endl;
        else
            cout << "Boring!" << endl;
    }
    return 0;
}