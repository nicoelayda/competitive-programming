#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;

    while (cin >> n >> m && (n != 0 || m != 0)) {
        unsigned long long c = 1;
        
        m = min(m, n-m);

        for (int i = 1; i <= m; i++)
            c = c * (n - m + i) / i;

        cout << c << endl;
    }
    return 0;
}