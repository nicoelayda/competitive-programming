#include <iostream>
#include <vector>

using namespace std;

const int col_offset[4] = {1, 0, -1, 0};
const int row_offset[4] = {0, 1, 0, -1};

bool is_border(int r, int c, int rows, int cols) {
    return r == 0 || c == 0 || r == rows - 1 || c == cols - 1;
}

int main() {
    int rows, cols;
    int wall_cost;
    int num_bumpers;

    cin >> cols >> rows;
    cin >> wall_cost;
    cin >> num_bumpers;

    vector< vector<int> > costs(rows, vector<int>(cols, 0));
    vector< vector<int> > points(rows, vector<int>(cols, 0));
    vector< vector<bool> > is_bumper(rows, vector<bool>(cols, false));

    while (num_bumpers-- != 0) {
        int r, c;
        cin >> c >> r;
        cin >> points[r-1][c-1] >> costs[r-1][c-1];
        is_bumper[r-1][c-1] = true;
    }

    int total_score = 0;

    int curr_row, curr_col;
    int direction;
    int life;

    while (cin >> curr_col >> curr_row >> direction >> life) {
        int curr_score = 0;

        curr_row -= 1;
        curr_col -= 1;

        while (life-- > 0) {
            int next_row = curr_row + row_offset[direction];
            int next_col = curr_col + col_offset[direction];

            if (is_border(next_row, next_col, rows, cols)) {
                direction = (direction + 3) % 4;
                life -= wall_cost;
            }
            else if (is_bumper[next_row][next_col]) {
                direction = (direction + 3) % 4;

                if (life > 0) {
                    curr_score += points[next_row][next_col];
                    life -= costs[next_row][next_col];
                }
            }
            else {
                curr_row = next_row;
                curr_col = next_col;
            }
        }

        cout << curr_score << endl;
        total_score += curr_score;
    }

    cout << total_score << endl;

    return 0;
}