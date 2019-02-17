#include <iostream>

using namespace std;

bool palindrome(string &word, int i, int j) {
    if (i == j + 1)
        return false;

    while (i < j) {
        if (word[i] != word[j])
            return false;

        i++, j--;
    }

    return true;
}

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        string word;
        cin >> word;
        bool alindrome = false;

        for (int i = 0; i < word.length() - 1; i++) {
            if (palindrome(word, 0, i) && palindrome(word, i + 1, word.length() - 1)) {
                alindrome = true;
                break;
            }
        }

        if (alindrome)
            cout << "alindrome" << endl;
        else if (palindrome(word, 0, word.length() - 1))
            cout << "palindrome" << endl;
        else
            cout << "simple" << endl;
    }


    return 0;
}