#include <iostream>
#include <algorithm>

using namespace std;

int cycle_length(int n) {
    int length = 1;

    while (n != 1) {
        length++;
        n = (n % 2 != 0) ? 3 * n + 1 : n / 2;
    }

    return length;
}

int max_cycle_length(int l_bound, int u_bound) {
    int max_length = 0;

    for (int n = l_bound; n <= u_bound; n++)
        max_length = max(cycle_length(n));

    return max_length;
}

int main() {
    int i, j;

    while (cin >> i >> j)
        cout << i << " " << j << " " << max_cycle_length(min(i, j), max(i, j)) << endl;

    return 0;
}