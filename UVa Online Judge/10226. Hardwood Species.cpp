#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main() {
    int T;
    string line;

    cin >> T;
    cin.ignore();	
    getline(cin, line);

    while (T-- != 0) {
        map<string, int> trees;
        int num_trees = 0;

        while (getline(cin, line) && line != "") {
            if (trees.find(line) == trees.end()) {
                trees[line] = 1;
            }
            else {
                trees[line]++;
            }

            num_trees++;
        }

        map<string, int>::iterator it;
        for (it = trees.begin(); it != trees.end(); ++it) {
            printf("%s %.4lf\n", (it->first).c_str(), 100.0 * it->second / num_trees);
        }

        if (T != 0)
            cout << endl;
    }

	return 0;
}