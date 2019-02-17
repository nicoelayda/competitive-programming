#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int triangular_index(int n) {
    return ceil(abs((sqrt(8*n + 1) - 1) / 2));
}

int triangular_num(int n) {
    return n * (n + 1) / 2;
}

int main() {
    int n;

    while (cin >> n) {
        int first, second;
        int level = triangular_index(n);
        int diff = triangular_num(level) - n;
        
        if (level % 2 == 0) {
            first = level - diff;
            second = diff + 1;
        }
        else {
            first = diff + 1;
            second = level - diff;
        }
        
        cout << "TERM " << n << " IS " << first << "/" << second << endl;
    }

    return 0;
}