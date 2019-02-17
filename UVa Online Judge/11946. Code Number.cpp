#include <iostream>

using namespace std;

char get_char(char ch) {
    switch (ch) {
        case '0': return 'O';
        case '1': return 'I';
        case '2': return 'Z';
        case '3': return 'E';
        case '4': return 'A';
        case '5': return 'S';
        case '6': return 'G';
        case '7': return 'T';
        case '8': return 'B';
        case '9': return 'P';
        default: return ch;
    }
}

int main () {
    int T;
    string line;
    cin >> T;
    cin.ignore();

    while (T-- != 0) {
        while (getline(cin, line) && line.length() != 0) {
            for (int i = 0; i < line.length(); i++) {
                cout << get_char(line[i]);
            }
            cout << endl;
        }
        
        if (T != 0) cout << endl;
    }
    
    return 0;
}