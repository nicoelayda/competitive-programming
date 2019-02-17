#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int row_offset[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int col_offset[8] = {2, -2, 2, -2, 1, -1, 1, -1};

struct state {
    int row, col;
    int cost;

    state(int _row, int _col, int _cost) {
        row = _row;
        col = _col;
        cost = _cost;
    }
};

bool valid_coord(int r, int c) {
    return r >= 0 && r < 8 && c >= 0 && c < 8;
}

int main() {
    string from, to;

    while (cin >> from >> to) {
        queue<state> fringe;
        vector < vector<bool> > visited(8, vector<bool>(8, false));
        fringe.push(state(from[1] - '1', from[0] - 'a', 0));

        int goal_row = to[1] - '1';
        int goal_col = to[0] - 'a';

        while (!fringe.empty()) {
            state curr = fringe.front(); fringe.pop();

            if (curr.row == goal_row && curr.col == goal_col) {
                cout << "To get from " << from << " to " << to << " takes " << curr.cost << " knight moves." << endl;
                break;
            }

            for (int i = 0; i < 8; i++) {
                int new_row = curr.row + row_offset[i];
                int new_col = curr.col + col_offset[i];

                if (valid_coord(new_row, new_col) && !visited[new_row][new_col]) {
                    fringe.push(state(new_row, new_col, curr.cost + 1));
                    visited[new_row][new_col] = true;
                }
            }
        }
    }

    return 0;
}