#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    string word;
    map<string, string> dictionary;
    
    while (cin >> word && word != "XXXXXX") {
        string sorted = word;
        
        sort(sorted.begin(), sorted.end());
        dictionary[word] = sorted;
    }

    while (cin >> word && word != "XXXXXX") {
        bool found = false;

        sort(word.begin(), word.end());

        map<string, string>::iterator it;
        for (it = dictionary.begin(); it != dictionary.end(); it++) {
            if (word == it->second) {
                cout << it->first << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "NOT A VALID WORD" << endl;
        }

        cout << "******" << endl;
    }
    return 0;
}