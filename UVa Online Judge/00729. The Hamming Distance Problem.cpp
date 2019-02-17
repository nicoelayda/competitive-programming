#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        int n, h;
        cin >> n >> h;
        string bit_string = string(n-h, '0') + string(h, '1');

        do {
            cout << bit_string << endl;
        } while (next_permutation(bit_string.begin(), bit_string.end()));

        if (T != 0)
            cout << endl;
    }
    
    return 0;
}