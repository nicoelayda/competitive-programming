#include <iostream>

using namespace std;

int rows, cols;
char map[101][101];

const int row_offset[8] = {0, 0, 1, -1, -1, -1, 1, 1};
const int col_offset[8] = {1, -1, 0, 0, -1, 1, -1, 1};

bool valid_coord(int r, int c) {
    return r >= 0 && r < rows && c >= 0 && c < cols;
}

void flood(int r, int c) {
    for (int i = 0; i < 8; i++) {
        int new_row = r + row_offset[i];
        int new_col = c + col_offset[i];

        if (valid_coord(new_row, new_col) && map[new_row][new_col] == '@') {
            map[new_row][new_col] = '*';
            flood(new_row, new_col);
        }
    }
}

int main() {
    while (cin >> rows >> cols) {
        if (rows == 0 && cols == 0) break;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                cin >> map[r][c];
            }
        }

        int deposits = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (map[r][c] == '@') {
                    deposits++;
                    map[r][c] = '*';
                    flood(r, c);
                }
            }
        }

        cout << deposits << endl;
    }

    return 0;
}