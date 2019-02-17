#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        int g, l;
        cin >> g >> l;

        if (l % g != 0)
            cout << -1 << endl;
        else
            cout << g << " " << l << endl;
    }
    return 0;
}