#include <iostream>
#include <algorithm>
#include <set>
#include <locale>

using namespace std;

string to_lower(string &str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }

    return str;
}

int main() {
    string line, word;
    set<string> dict;

    while (getline(cin, line)) {
        word = "";
        for (int i = 0; i < line.length(); i++) {
            if (isalpha(line[i])) {
                word += line[i];
            }
            else if (word.length() != 0) {
                dict.insert(to_lower(word));
                word = "";
            }
        }

        if (word.length() != 0) 
            dict.insert(to_lower(word));
    }
    
    set<string>::iterator it;
    for (it = dict.begin(); it != dict.end(); it++) 
        cout << *it << endl;
    
    return 0;   
}