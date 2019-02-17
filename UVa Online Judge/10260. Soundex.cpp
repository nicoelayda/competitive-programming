#include <iostream>
#include <string>

using namespace std;

string code_table[7] = {"AEIOUYWH", "BPFV", "CSKGJQXZ", "DT", "L", "MN", "R"};

char char_code(char ch) {
    for (int i = 0; i <= 6; i++)
        if (code_table[i].find(ch) != string::npos)
            return '0' + i;

    return '0';
}

int main() {
    string name;

    while (cin >> name) {
        char last = '0';
        string soundex_code = "";

        for (int i = 0; i < name.length(); i++) {
            char ch = char_code(name[i]);

            if (ch != '0' && ch != last)
                soundex_code += ch;

            last = ch;
        }

        cout << soundex_code << endl;
    }
    return 0;
}