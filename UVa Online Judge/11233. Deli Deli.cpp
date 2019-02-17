#include <iostream>
#include <map>
#include <string>

using namespace std;

bool ends_with(string str, string ending) {
    if (str.length() < ending.length())
        return false;

    return str.compare(str.length() - ending.length(), ending.length(), ending) == 0;
}

bool is_vowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main() {
    int l, n;
    cin >> l >> n;

    string word, plural;
    map<string, string> irregular;

    while (l-- != 0) {
        cin >> word >> plural;
        irregular[word] = plural;
    }

    while (n-- != 0) {
        cin >> word;

        if (irregular[word].length() != 0)
            cout << irregular[word] << endl;
        else if (word.length() > 1 && ends_with(word, "y") && !is_vowel(word[word.length() - 2]))
            cout << word.substr(0, word.length() - 1) << "ies" << endl;
        else if (ends_with(word, "o") || ends_with(word, "s") || ends_with(word, "ch") || ends_with(word, "sh") || ends_with(word, "x"))
            cout << word << "es" << endl;
        else
            cout << word << "s" << endl;
    }

    return 0;
}