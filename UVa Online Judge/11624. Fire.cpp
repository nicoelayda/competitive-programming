#include <iostream>
#include <queue>

using namespace std;

const int row_offset[4] = {0, 0, -1, 1};
const int col_offset[4] = {-1, 1, 0, 0};

int rows, cols;

struct state {
    int row, col;
    int cost;
    state(int i_row, int i_col, int i_cost) {
        row = i_row;
        col = i_col;
        cost = i_cost;
    }
};

bool valid_coord(int r, int c) {
    return r >= 0 && r < rows && c >= 0 && c < cols;
}

bool border_coord(int r, int c) {
    return r == 0 || c == 0 || r == rows - 1 || c == cols - 1;
}

int main() {
    int cases;
    cin >> cases;

    while (cases-- != 0) {
        cin >> rows >> cols;

        char map[rows][cols];
        int fire_map[rows][cols];
        bool escaped = false;

        queue<state> fire_fringe;
        queue<state> joe_fringe;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                cin >> map[r][c];
                fire_map[r][c] = -1;

                if (map[r][c] == 'J') {
                    joe_fringe.push(state(r, c, 0));
                    map[r][c] = '#';
                }
                else if (map[r][c] == 'F') {
                    fire_fringe.push(state(r, c, 0));
                    fire_map[r][c] = 0;
                }
            }
        }

        while (!fire_fringe.empty()) {
            state curr = fire_fringe.front(); fire_fringe.pop();

            for (int i = 0; i < 4; i++) {
                int new_row = curr.row + row_offset[i];
                int new_col = curr.col + col_offset[i];

                if (valid_coord(new_row, new_col) && fire_map[new_row][new_col] == -1 && map[new_row][new_col] != '#') {
                    fire_map[new_row][new_col] = curr.cost + 1;
                    fire_fringe.push(state(new_row, new_col, curr.cost + 1));
                    
                }
            }
        }

        while (!joe_fringe.empty()) {
            state curr = joe_fringe.front(); joe_fringe.pop();

            if (border_coord(curr.row, curr.col)) {                
                cout << (curr.cost + 1) << endl;
                escaped = true;
                break;
            }

            for (int i = 0; i < 4; i++) {
                int new_row = curr.row + row_offset[i];
                int new_col = curr.col + col_offset[i];

                if (valid_coord(new_row, new_col) && (curr.cost + 1 <= fire_map[new_row][new_col] || fire_map[new_row][new_col] == -1) && map[new_row][new_col] != '#') {
                    joe_fringe.push(state(new_row, new_col, curr.cost + 1));
                    map[new_row][new_col] = '#';
                }
            }
        }

        if (!escaped)
            cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}