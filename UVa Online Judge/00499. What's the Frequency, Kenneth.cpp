#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
vector< pair<char, int> > frequency;

size_t get_index(char ch) {
    return alphabet.find(ch);
}

bool is_alpha(char ch) {
    return get_index(ch) != string::npos;
}

bool compare(pair<char, int> p1, pair<char, int> p2) {
    if (p1.second == p2.second)
        return p1.first < p2.first;
    else
        return p1.second > p2.second;
}

int main() {
    string line;
    for (int i = 0; i < alphabet.size(); i++)
        frequency.push_back(make_pair(alphabet[i], 0));

    while (getline(cin, line)) {
        for (int i = 0; i < frequency.size(); i++) {
            frequency[i].first = alphabet[i];
            frequency[i].second = 0;
        }

        for (int i = 0; i < line.length(); i++) {
            if (is_alpha(line[i])) {
                frequency[get_index(line[i])].second++;
            }
        }

        sort(frequency.begin(), frequency.end(), compare);

        int max_val = frequency[0].second;
        for (int i = 0; i < frequency.size(); i++) {
            if (frequency[i].second != max_val) break;
            cout << frequency[i].first;
        }
        cout << " " << max_val << endl;
    }
    return 0;
}