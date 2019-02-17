#include <cstdio>

using namespace std;

const int row_offset[8] = {1, -1, 0, 0, -1, -1, 1, 1};
const int col_offset[8] = {0, 0, 1, -1, -1, 1, -1, 1};

int rows, cols;
char sky[100][100];

bool valid_coord(int r, int c) {
    return r >= 0 && r < rows && c >= 0 && c < cols;
}

bool has_adj(int r, int c, char sky[][100]) {
    bool has_adjacent = false;

    for (int i = 0; i < 8; i++) {
        int new_row = r + row_offset[i];
        int new_col = c + col_offset[i];

        if (valid_coord(new_row, new_col) && sky[new_row][new_col] == '*') {
            has_adjacent = true;
            break;
        }
    }

    return has_adjacent;
}

int main() {
    while (scanf("%d %d", &rows, &cols) == 2 && rows != 0 && cols != 0) {
        for (int i = 0; i < rows; i++) {
            scanf("%s", sky[i]);
        }

        int stars = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (sky[i][j] == '*' && !has_adj(i, j, sky)) {
                    stars++;
                }
            }
        }
        printf("%d\n", stars);
    }
    return 0;
}