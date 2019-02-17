#include <iostream>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

int main() {
    int T;
    string phrase, sorted_phrase;
    
    cin >> T;
    cin.ignore();
    getline(cin, phrase);

    while (T-- != 0) {
        map<string, string> anagrams;

        while (getline(cin, phrase) && phrase != "") {
            sorted_phrase = phrase;
            sort(sorted_phrase.begin(), sorted_phrase.end());

            sorted_phrase = sorted_phrase.substr(sorted_phrase.find_first_not_of(" "));
            anagrams[phrase] = sorted_phrase;
        }

        map<string, string>::iterator it_i, it_j;
        for (it_i = anagrams.begin(); it_i != anagrams.end(); advance(it_i, 1)) {
            for (it_j = it_i, advance(it_j, 1); it_j != anagrams.end(); advance(it_j, 1)) {
                if (it_i->second == it_j->second)
                    cout << it_i->first << " = " << it_j->first << endl;
            }
        }

        if (T != 0)
            cout << endl;
    }

    return 0;
}