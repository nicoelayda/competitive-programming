#include <iostream>
#include <utility>
#include <cmath>

using namespace std;

int to_dec(string str, int base) {
    int dec = 0;

    for (int i = 0; i < str.length(); i++) {
        dec += (str[str.length() - i - 1] - '0') * pow(base, i);
    }

    return dec;
}

pair<int, int> split(string str) {
    string a = string(str.length(), '0');
    string b = string(str.length(), '0');
    int pos = 0;

    for (int i = str.length() - 1; i >= 0; i--) {
        if (str[i] == '1') {
            if (pos++ % 2 == 0)
                a[i] = '1';
            else
                b[i] = '1';
        }
    }

    return make_pair(to_dec(a, 2), to_dec(b, 2));
}

string to_binary(int n) {
    if (n == 0) return "0";
    if (n == 1) return "1";

    return to_binary(n >> 1) + (n % 2 == 0 ? "0" : "1");
}

int main() {
    int n;

    while (cin >> n && n != 0) {
        pair<int, int> ab = split(to_binary(n));
        cout << ab.first << " " << ab.second << endl;
    }


    return 0;
}