#include <iostream>
#include <locale>
#include <map>

using namespace std;

char char_map(char ch) {
    switch (ch) {
        case 'A': case 'B': case 'C':
            return '2';
        case 'D': case 'E': case 'F':
            return '3';
        case 'G': case 'H': case 'I':
            return '4';
        case 'J': case 'K': case 'L':
            return '5';
        case 'M': case 'N': case 'O':
            return '6';
        case 'P': case 'R': case 'S':
            return '7';
        case 'T': case 'U': case 'V':
            return '8';
        case 'W': case 'X': case 'Y':
            return '9';
    }
}

string teleformat(string str) {
    string tel = string();

    for (int i = 0; i < str.length(); i++) {
        if (tel.length() == 3)
            tel += "-";

        if (isalpha(str[i]))
            tel += char_map(str[i]);
        else if (isdigit(str[i]))
            tel += str[i];
    }

    return tel;
}

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        int num_numbers;
        string number;
        map<string, int> numbers;

        cin >> num_numbers;

        while (num_numbers-- != 0) {
            cin >> number;
            numbers[teleformat(number)]++;
        }

        bool duplicates = false;

        map<string, int>::iterator it;
        for (it = numbers.begin(); it != numbers.end(); it++) {
            if (it->second > 1) {
                cout << (it->first) << " " << (it->second) << endl;
                duplicates = true;
            }
        }

        if (!duplicates)
            cout << "No duplicates." << endl;

        if (T != 0)
            cout << endl;
    }

    return 0;
}