#include <iostream>
#include <vector>

using namespace std;

bool has_repeat(int n) {
    vector<bool> used(10, false);

    while (n != 0) {
        int d = n % 10;
        
        if (!used[d]) {
            used[d] = true;
            n /= 10;
        }
        else
            return true;
    }

    return false;
}

int main() {
    int n, m;

    while (cin >> n >> m) {
        int usable = 0;

        for (int i = n; i <= m; i++) {
            if (!has_repeat(i))
                usable++;
        }
        cout << usable << endl;
    }

    return 0;
}