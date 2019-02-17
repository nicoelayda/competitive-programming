#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

void trim(string &str) {
    str.erase(str.find_last_not_of(" ") + 1);
    str.erase(0, str.find_first_not_of(" "));
}

int main() {
    string line;

    while (getline(cin, line)) {
        vector<int> isbn;
        vector<int> s1;

        trim(line);

        for (int i = 0; i < line.length(); i++) {
            if (line[i] >= '0' && line[i] <= '9') {
                isbn.push_back(line[i] - '0');
                
                if (s1.size() == 0)
                    s1.push_back(isbn[isbn.size() - 1]);
                else
                    s1.push_back(isbn[isbn.size() - 1] + s1[s1.size() - 1]);
            }
            else if (isbn.size() == 9 && line[i] == 'X') {
                isbn.push_back(10);
                s1.push_back(10 + s1[s1.size() - 1]);
            }
        }

        if (isbn.size() == 10 && accumulate(s1.begin(), s1.end(), 0) % 11 == 0)
            cout << line << " is correct." << endl;
        else
            cout << line << " is incorrect." << endl;
    }

    return 0;
}