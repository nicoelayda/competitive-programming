#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int costs[36] = {2, 3, 3, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 11, 11, 12};

bool comparator(pair<char, int> p1, pair<char, int> p2) {
    return p1.second > p2.second;
}

bool is_alphanumeric(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

int get_ch_index(vector<pair<char, int> > v, char ch) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i].first == ch) {
            return i;
        }
    }

    return -1;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T-- != 0) {
        vector<pair<char, int> > frequency;
        string line;

        getline(cin, line);

        // frequency count
        for (int i = 0; i < line.length(); i++) {
            if (is_alphanumeric(line[i])) {
                int ch_index = get_ch_index(frequency, line[i]);
                
                if (ch_index == -1) {
                    frequency.push_back(make_pair(line[i], 1));
                }
                else {
                    frequency[ch_index].second++;
                }
            }
        }

        sort(frequency.begin(), frequency.end(), comparator);

        // calculation
        int cost = 0;
        for (int i = 0; i < frequency.size(); i++) {
            cost += frequency[i].second * costs[i];
        }

        cout << cost << endl;

    }

    return 0;   
}