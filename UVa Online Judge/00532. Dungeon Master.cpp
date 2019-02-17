#include <iostream>
#include <queue>

using namespace std;

const int lvl_offset[6] = {0, 0, 0, 0, 1, -1};
const int row_offset[6] = {1, -1, 0, 0, 0, 0};
const int col_offset[6] = {0, 0, -1, 1, 0, 0};

int levels, rows, columns;

struct state {
    int lvl, row, col;
    int cost;
    state(int i_lvl, int i_row, int i_col, int i_cost) {
        lvl = i_lvl;
        row = i_row;
        col = i_col;
        cost = i_cost;
    }
};

bool valid_coord(int l, int r, int c) {
    return l >= 0 && l < levels && r >= 0 && r < rows && c >= 0 && c < columns;
}

int main() {
    while (cin >> levels >> rows >> columns) {
        if (levels == 0 && rows == 0 && columns == 0)
            break;

        int start_row, start_col, start_lvl;
        char map[levels][rows][columns];
        
        for (int l = 0; l < levels; l++) {
            for (int r = 0; r < rows; r++) {
                for (int c = 0; c < columns; c++) {
                    cin >> map[l][r][c];
                    if (map[l][r][c] == 'S') {
                        start_lvl = l;
                        start_row = r;
                        start_col = c;
                        map[l][r][c] = '#';
                    }
                }
            }
        }


        bool escaped = false;
        queue<state> fringe;
        fringe.push(state(start_lvl, start_row, start_col, 0));

        while (!fringe.empty() && !escaped) {
            state curr = fringe.front(); fringe.pop();

            for (int i = 0; i < 6; i++) {
                int new_lvl = curr.lvl + lvl_offset[i];
                int new_row = curr.row + row_offset[i];
                int new_col = curr.col + col_offset[i];

                if (valid_coord(new_lvl, new_row, new_col) && map[new_lvl][new_row][new_col] != '#') {
                    if (map[new_lvl][new_row][new_col] == 'E') {
                        cout << "Escaped in " << (curr.cost + 1) << " minute(s)." << endl;
                        escaped = true;
                        break;
                    }

                    fringe.push(state(new_lvl, new_row, new_col, curr.cost + 1));
                    map[new_lvl][new_row][new_col] = '#';
                }
            }
        }

        if (!escaped)
            cout << "Trapped!" << endl;
    }

    return 0;
}