#include <iostream>

using namespace std;

const int row_offset[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int col_offset[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n;
char image[25][25];

bool valid_coord(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

void flood(int r, int c) {
    if (image[r][c] == '1') {
        image[r][c] = 'X';
        for (int i = 0; i < 8; i++) {
            int new_row = r + row_offset[i];
            int new_col = c + col_offset[i];

            if (valid_coord(new_row, new_col))
                flood(new_row, new_col);
        }
    }
}

int main() {
    int image_num = 0;
    while (cin >> n) {
        int eagles = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> image[i][j];
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (image[i][j] == '1') {
                    eagles++;
                    flood(i, j);
                }
            }
        }

        cout << "Image number " << ++image_num << " contains " << eagles << " war eagles." << endl;
    }
    return 0;
}