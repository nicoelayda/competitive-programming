#include <iostream>
using namespace std;

void print_location(int n, int m, int x, int y) {
    if (n == x || m == y)
        cout << "divisa" << endl;
    else if (x > n && y > m)
        cout << "NE" << endl;
    else if (x < n && y < m)
        cout << "SO" << endl;
    else if (x > n && y < m)
        cout << "SE" << endl;
    else if (x < n && y > m)
        cout << "NO" << endl;
}

int main() {
    int k;
    while (cin >> k && k != 0) {
        int n, m;
        cin >> n >> m;
        while (k-- != 0) {
            int x, y;
            cin >> x >> y;
            print_location(n, m, x, y);
        }
    }

    return 0;
}