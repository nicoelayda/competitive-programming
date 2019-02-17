#include <iostream>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();

    for (int tc = 1; tc <= T; tc++) {
        string line;
        getline(cin, line);

        cout << "Case " << tc << ": ";

        for (int i = 0; i < line.length(); i++) {
            char ch = line[i];
            int j = i + 1;

            while (j < line.length() && line[j] >= '0' && line[j] <= '9')
                j++;

            cout << string(stoi(line.substr(i + 1, j - (i + 1))), ch);
            i = j - 1;
        }

        cout << endl;
    }
    
    return 0;
}