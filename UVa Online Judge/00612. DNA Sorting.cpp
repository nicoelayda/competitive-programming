#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int inversion(const string &str) {
    int inversion_factor = 0;

    for (int i = 0; i < str.size(); i++) {
        for (int j = i + 1; j < str.size(); j++) {
            if (str[i] > str[j]) {
                inversion_factor++;
            }
        }
    }

    return inversion_factor;
}

bool comparator(pair<int, string> p1, pair<int, string> p2) {
    return p1.first < p2.first;
}

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        int length, num_strings;
        cin >> length >> num_strings;

        string str;
        vector< pair<int, string> > data;

        while (num_strings-- != 0) {
            cin >> str;
            data.push_back(make_pair(inversion(str), str));
        }

        stable_sort(data.begin(), data.end(), comparator);

        for (int i = 0; i < data.size(); i++)
            cout << data[i].second << endl;

        if (T != 0)
            cout << endl;
    }
    return 0;
}