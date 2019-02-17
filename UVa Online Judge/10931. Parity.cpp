#include <iostream>

using namespace std;

string bin_str(int n) {
    if (n == 0)
        return "0";
    else if (n == 1)
        return "1";

    return bin_str(n / 2) + (n % 2 == 0 ? "0" : "1");
}

int main() {
    int n;

    while (cin >> n && n != 0) {
        string bin = bin_str(n);
        int ones = 0;

        for (int i = 0; i < bin.length(); i++) {
            if (bin[i] == '1')
                ones++;
        }
        cout << "The parity of " << bin << " is " << ones << " (mod 2)." << endl;
    }

    return 0;
}