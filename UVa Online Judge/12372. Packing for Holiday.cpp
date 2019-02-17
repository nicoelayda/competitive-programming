#include <iostream>

using namespace std;

int main() {
    int t, l, w, h;
    cin >> t;
    for (int case_num = 1; case_num <= t; case_num++) {
        cin >> l >> w >> h;
        bool good = l <= 20 && w <= 20 && h <= 20;
        cout << "Case " << case_num << ": " << (good ? "good" : "bad") << endl;
    }

    return 0;
}