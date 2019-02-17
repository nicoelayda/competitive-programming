#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

vector<string> phrases;

bool comparator(pair<string, string> p1, pair<string, string> p2) {
    if (p1.first == p2.first) {
        transform(p1.second.begin(), p1.second.end(), p1.second.begin(), ::tolower);
        transform(p2.second.begin(), p2.second.end(), p2.second.begin(), ::tolower);

        return find(phrases.begin(), phrases.end(), p1.second) < find(phrases.begin(), phrases.end(), p2.second);
    }

    return p1.first < p2.first;
}

int main() {
    string line;
    set<string> ignore;
    vector<pair<string, string> > kwic;

    // read ignored words
    while (getline(cin, line) && line != "::") {
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        ignore.insert(line);
    }

    // read phrases
    while (getline(cin, line)) {
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        phrases.push_back(line);

        stringstream sstr(line);
        string word;

        size_t pos = 0;
        while (sstr >> word) {
            if (ignore.find(word) == ignore.end()) {
                string kwic_entry = line;
                pos = kwic_entry.find(word, pos);                
                string::iterator kwic_it = kwic_entry.begin() + pos;

                transform(kwic_it, kwic_it + word.length(), kwic_it, ::toupper);

                pos += word.length();

                kwic.push_back(make_pair(word, kwic_entry));
            }
        }
    }

    stable_sort(kwic.begin(), kwic.end(), comparator);

    for (int i = 0; i < kwic.size(); i++) {
        cout << kwic[i].second << endl;
    }

    return 0;
}