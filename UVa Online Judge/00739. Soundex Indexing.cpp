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

    cout << string(9, ' ') << "NAME" << string(21, ' ') << "SOUNDEX CODE" << endl;

    while (cin >> name) {
        char last = '0';
        string soundex_code = "";
        
        for (int i = 0; i < name.length() && soundex_code.length() < 4; i++) {
            char ch = char_code(name[i]);

            if (i == 0)
                soundex_code += name[i];
            
            else if (ch != '0' && ch != last)
                soundex_code += ch;
            
            last = ch;
        }


        while (soundex_code.length() < 4)
            soundex_code += '0';

        cout << string(9, ' ') << name << string(25 - name.length(), ' ') << soundex_code << endl;
    }

    cout << string(19, ' ') << "END OF OUTPUT" << endl;
    return 0;
}