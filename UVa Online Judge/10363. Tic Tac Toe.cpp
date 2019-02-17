#include <iostream>
#include <cmath>

using namespace std;

char grid[3][3];

bool has_win(char ch) {
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] == ch && grid[i][1] == ch && grid[i][2] == ch)
            return true;

        if (grid[0][i] == ch && grid[1][i] == ch && grid[2][i] == ch)
            return true;
    }

    if (grid[0][0] == ch && grid[1][1] == ch && grid[2][2] == ch)
        return true;

    if (grid[0][2] == ch && grid[1][1] == ch && grid[2][0] == ch)
        return true;

    return false;
}

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        int x = 0, o = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == 'X')
                    x++;
                else if (grid[i][j] == 'O')
                    o++;
            }
        }

        bool x_wins = has_win('X');
        bool o_wins = has_win('O');

        if ((x_wins && o_wins) || (x_wins && x - o != 1) || (o_wins && x - o != 0) || (x - o != 1 && x - o != 0))
            cout << "no" << endl;
        else
            cout << "yes" << endl;
    }
    return 0;
}