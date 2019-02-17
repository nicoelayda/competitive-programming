#include <iostream>
#include <map>
#include <cctype>

using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T-- != 0) {
        string line;
        map<char, int> frequency;

        for (char ch = 'a'; ch <= 'z'; ch++) {
            frequency[ch] = 0;
        }

        getline(cin, line);

        int max_freq = 0;
        for (int i = 0; i < line.length(); i++) {
            if (isalpha(line[i])) {
                frequency[tolower(line[i])]++;
                max_freq = max(max_freq, frequency[tolower(line[i])]);
            }
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (frequency[ch] == max_freq)
                cout << ch;
        }
        cout << endl;

    }
    return 0;
}