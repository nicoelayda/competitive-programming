#include <iostream>
#include <sstream>

using namespace std;

bool is_vowel(char ch) {
    ch = toupper(ch);
    return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

string to_pig_latin(string word) {
    if (word.length() == 0)
        return "";

    if (is_vowel(word[0]))
        return word + "ay";
    else
        return word.substr(1) + string(1, word[0]) + "ay";
}

int main() {
    string line;
    while (getline(cin, line)) {
        stringstream ss;
        for (int i = 0; i < line.length(); i++) {
            if (!isalpha(line[i])) {
                cout << to_pig_latin(ss.str()) << line[i];
                ss.str(string());
                ss.clear();
            }
            else {
                ss << line[i];
            }
        }
        cout << to_pig_latin(ss.str()) << endl;
    }
    return 0;
}