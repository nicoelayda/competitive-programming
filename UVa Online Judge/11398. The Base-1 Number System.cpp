#include <iostream>
#include <cmath>

using namespace std;

int to_decimal(string bin) {
    int dec = 0;

    for (int i = bin.length() - 1; i >= 0; i--) {
        if (bin[i] == '1') {
            dec += pow(2, bin.length() - i - 1);
        }
    }

    return dec;
}

int main() {
    string block;

    while (cin >> block && block != "~") {
        char flag = block.length() == 1 ? '1' : '0';
        string binary = "";

        while (cin >> block && block != "#") {
            switch (block.length()) {
                case 1:
                    flag = '1';
                    break;
                case 2:
                    flag = '0';
                    break;
                default:
                    binary += string(block.length() - 2, flag);
            }
        }

        cout << to_decimal(binary) << endl;
    }
    return 0;
}