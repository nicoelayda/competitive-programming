#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string line;

    while (cin >> line && line != "#") {
        string original = line;
        next_permutation(line.begin(), line.end());

        if (lexicographical_compare(original.begin(), original.end(), line.begin(), line.end()))
            cout << line << endl;
        else
            cout << "No Successor" << endl;
    }
    return 0;
}