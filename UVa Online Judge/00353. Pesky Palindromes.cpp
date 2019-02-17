#include <iostream>
#include <set>

using namespace std;

bool is_palindrome(string str) {
    for (int i = 0; i < str.size() / 2; i++) {
        if (str[i] != str[str.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    string line;

    while (getline(cin, line)) {
        set<string> palindromes;

        for (int len = 1; len <= line.length(); len++) {
            for (int i = 0; i <= line.length() - len; i++) {
                string substring = line.substr(i, len);

                if (is_palindrome(substring)) {
                    palindromes.insert(substring);
                }
            }
        }

        cout << "The string '" << line << "' contains " << palindromes.size() << " palindromes." << endl;
    }

    return 0;
}