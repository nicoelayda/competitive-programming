#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b;

    while (cin >> a >> b && a != 0 && b != 0) {
        int squares = 0;

        for (int i = ceil(sqrt(a)); i*i <= b; i++) {
                squares++;
        }

        cout << squares << endl;
    }
    return 0;
}