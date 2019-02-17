#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T;
    string str;

    cin >> T;

    while (T-- != 0) {
        cin >> str;
        sort(str.begin(), str.end());

        do {
            cout << str << endl;
        } while (next_permutation(str.begin(), str.end()));

        cout << endl;
    }
    return 0;
}