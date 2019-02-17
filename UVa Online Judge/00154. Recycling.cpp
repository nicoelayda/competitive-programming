#include <iostream>
#include <algorithm>
#include <limits>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(string str, char delim) {
    vector<string> elems;
    istringstream iss(str);
    string token;

    while (getline(iss, token, delim)) {
        elems.push_back(token);
    }

    sort(elems.begin(), elems.end());

    return elems;
}

int diff(vector<string> &city1, vector<string> &city2) {
    int changes = 0;

    for (int i = 0; i < city1.size(); i++) {
        if (city1[i] != city2[i])
            changes++;
    }

    return changes;
}

int main() {
    bool done = false;

    while (!done) {
        string line;
        vector< vector<string> > block;

        while (getline(cin, line)) {
            if (line[0] == '#') {
                done = true;
                break;
            }
            else if (line[0] == 'e') {
                break;
            }

            block.push_back(split(line, ','));
        }

        if (done) break;

        int min_city = 1;
        int min_changes = numeric_limits<int>::max();
        
        for (int i = 0; i < block.size(); i++) {
            int changes = 0;

            for (int j = 0; j < block.size(); j++) {
                if (i != j) {
                    changes += diff(block[i], block[j]);
                }
            }

            if (changes < min_changes) {
                min_changes = changes;
                min_city = i + 1;
            }
        }
        cout << min_city << endl;
    }

    return 0;
}