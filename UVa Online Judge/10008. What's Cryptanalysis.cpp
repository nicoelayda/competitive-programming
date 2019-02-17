#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct letter {
    char ch;
    int count;

    letter(char ch) {
        this->ch = ch;
        this->count = 0;
    }
};

char to_uppercase(char ch) {
    if (ch >= 'a' && ch <= 'z')
        ch -= 32;

    return ch;
}

bool compare(letter l1, letter l2) {
    if (l1.count == l2.count)
        return l1.ch < l2.ch;
    else
        return l1.count > l2.count;
}

int main() {
    int n;
    string line;
    cin >> n;

    vector<letter> letters;

    for (int i = 0; i < 26; i++)
        letters.push_back(letter('A' + i));

    while (getline(cin, line)) {
        for (int i = 0; i < line.length(); i++) {
            char ch = to_uppercase(line[i]);
            if (ch >= 'A' && ch <= 'Z') {
                letters[ch - 'A'].count++;
            }
        }
    }
    
    sort(letters.begin(), letters.end(), compare);

    for (int i = 0; i < letters.size(); i++) {
        if (letters[i].count == 0) break;
        cout << letters[i].ch << " " << letters[i].count << endl;
    }
    return 0;
}