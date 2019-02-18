#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int score_of(string str, int pos) {
    int score = 0;

    for (int i = 0; i < str.length(); i++)
        score += str[i] - 'A' + 1;

    return score * pos;
}

int main() {
    string name;
    vector<string> names;

    while (cin >> name)
        names.push_back(name);

    sort(names.begin(), names.end());

    int total = 0;
    for (int i = 0; i < names.size(); i++)
        total += score_of(names[i], i + 1);

    cout << total << endl;

    return 0;
}