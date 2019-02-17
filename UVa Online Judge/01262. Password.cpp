#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int passwords_generated;
set<string> passwords;

void find_nth_password(int n, string password, vector<char> characters[5]) {
    if (password.length() == 5 && passwords.find(password) == passwords.end()) {
        passwords.insert(password);
        passwords_generated++;

        if (passwords_generated == n)
            cout << password << endl;
    }
    else if (password.length() < 5 && passwords_generated < n) {
        int ch_index = password.length();

        for (int i = 0; i < characters[ch_index].size(); i++)
            find_nth_password(n, password + characters[ch_index][i], characters);
    }
}

int main() {
    int T, index;
    char grid1[7][7], grid2[7][7];
    
    cin >> T;

    while (T-- != 0) {
        cin >> index;
        // parse grid 1
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 5; j++)
                cin >> grid1[j][i];

        // parse grid 2
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 5; j++)
                cin >> grid2[j][i];

        // get intersection of grid's columns
        vector<char> intersection[5];
        for (int i = 0; i < 5; i++) {
            int g1 = 0, g2 = 0;

            sort(grid1[i], grid1[i] + 6);
            sort(grid2[i], grid2[i] + 6);

            while (g1 != 6 && g2 != 6) {
                if (grid1[i][g1] < grid2[i][g2])
                    g1++;
                else if (grid1[i][g1] > grid2[i][g2])
                    g2++;

                if (grid1[i][g1] == grid2[i][g2]) {
                    intersection[i].push_back(grid1[i][g1]);
                    g1++;
                    g2++;
                }
            }
        }

        passwords.clear();
        passwords_generated = 0;

        find_nth_password(index, "", intersection);

        if (passwords_generated < index)
            cout << "NO" << endl;

    }
    return 0;
}