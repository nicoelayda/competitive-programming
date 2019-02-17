#include <iostream>
#include <map>

using namespace std;

map<string, int> words;
int words_generated = 0;

void generate(string word, int word_length) {
    if (word.length() == word_length) {
        words[word] = ++words_generated;
    }
    else {
        char last = word.length() != 0 ? word[word.length() - 1] + 1 : 'a';

        for (char ch = last; ch <= 'z'; ch++)
            generate(word + ch, word_length);    
    }
}

int main() {
    string line;

    for (int i = 1; i <= 5; i++)
        generate("", i);

    while (cin >> line)
        cout << words[line] << endl;

    return 0;
}