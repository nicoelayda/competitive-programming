#include <iostream>
#include <cmath>

using namespace std;

bool is_magic(string str) {
    int root = floor(sqrt(str.length()));

    if (root != sqrt(str.length()))
        return false;

    for (int i = 0; i < root; i++) {
        for (int j = 0; j < root; j++) {
            if (str[i * root + j] != str[str.length() - (i * root + j) - 1] || 
                str[j * root + i] != str[str.length() - (j * root + i) - 1] ||
                str[i * root + j] != str[j * root + i]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();

    for (int tc = 1; tc <= T; tc++) {
        string line;
        getline(cin, line);

        string trimmed = "";
        for (int i = 0; i < line.length(); i++) {
            if (isalpha(line[i])) {
                trimmed += line[i];
            }
        }

        cout << "Case #" << tc << ":" << endl;
        
        if (is_magic(trimmed))
            cout << sqrt(trimmed.length()) << endl;
        else
            cout << "No magic :(" << endl;
    }

    return 0;
}