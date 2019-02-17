#include <iostream>

using namespace std;

int weight(int n) {
    if (n == 1) return 500;
    if (n == 0) return 250;
    return weight(n >> 1) + (n % 2 == 0 ? 250 : 500);
}

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int left_lvl = -1, right_lvl = -1;
        int left_weight = 0, right_weight = 0;
        string left_weights = "", right_weights = "";

        char grid[7][18];

        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 18; j++) {
                cin >> grid[i][j];

                if (grid[i][j] == '/') {
                    if (j < 8 && left_lvl == -1)
                        left_lvl = i + 1;
                    else if (j > 9 && right_lvl == -1)
                        right_lvl = i + 1;
                }
                else if (isalpha(grid[i][j])) {
                    if (j < 8)
                        left_weight += weight(grid[i][j]);
                    else if (j > 9)
                        right_weight += weight(grid[i][j]);
                }
            }
        }

        cin.ignore(256, '\n');
        cin.ignore(256, '\n');

        int left_correct, right_correct;

        if (left_weight < right_weight) 
            left_correct = 1, right_correct = 3;
        else if (left_weight > right_weight)
            left_correct = 3, right_correct = 1;
        else
            left_correct = 2, right_correct = 2;
        
        cout << "Case " << tc << ":" << endl;

        if (left_correct == left_lvl && right_correct == right_lvl) {
            cout << "The figure is correct." << endl;
        }
        else {
            for (int i = 0; i < 7; i++) {
                for (int j = 0; j < 8; j++) {
                    int new_i = i + left_lvl - left_correct;
                    cout << (new_i < 0 || new_i >= 7 ? '.' : grid[new_i][j]);
                }

                cout << "||";

                for (int j = 10; j < 18; j++) {
                    int new_i = i + right_lvl - right_correct;
                    cout << (new_i < 0 || new_i >= 7 ? '.' : grid[new_i][j]);
                }
                cout << endl;
            }
        }
    }
    return 0;
}