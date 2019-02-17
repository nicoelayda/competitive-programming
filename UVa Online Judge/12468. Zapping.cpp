#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int a, b;

    while (cin >> a >> b) {
        if (a == -1 && b == -1)
            break;

        cout << min(abs(a - b), 100 + min(a, b) - max(a, b)) << endl;
    }
    return 0;    
}