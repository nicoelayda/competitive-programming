#include <iostream>
#include <algorithm>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

int prefix_length(const string &s1, const string &s2) {
    int prefix = 0;
    int len = min(s1.length(), s2.length());

    for (int i = 0; i < len && s1[i] == s2[i]; i++)
        prefix++;

    return prefix;
}

int diff(const string &s1, const string &s2) {
    int diff = s2.length();
    int len = min(s1.length(), s2.length());

    for (int i = 0; i < len && s1[i] == s2[i]; i++)
        diff--;

    return diff;
}

bool comparator(const pair<string, int> s1, const pair<string, int> s2) {
    if (s1.second == s2.second)
        return s1.first < s2.first;

    return s1.second > s2.second;
}

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        int num_words;
        string first, word;

        cin >> num_words >> first;

        vector< pair<string, int> > words;

        for (int i = 1; i < num_words; i++) {
            cin >> word;
            words.push_back(make_pair(word, prefix_length(first, word)));
        }

        sort(words.begin(), words.end(), comparator);

        ostringstream word_order;
        int presses = first.length();
        string last = first;

        word_order << first << endl;

        for (int i = 0; i < words.size(); i++) {
            word_order << words[i].first << endl;
            presses += diff(last, words[i].first);
            last = words[i].first;
        }

        cout << presses << endl;
        cout << word_order.str();
    }

    return 0;
}