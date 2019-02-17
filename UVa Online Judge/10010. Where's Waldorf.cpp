#include <cstdio>
#include <cstring>
using namespace std;

int rows, cols;

char grid[50][51];
char word[51];

bool ch_equal(char a, char b) {
    if (a >= 'a' && a <= 'z') a -= 32;
    if (b >= 'a' && b <= 'z') b -= 32;

    return a == b;    
}

bool search(int r, int c) {
    bool found = false;
    int len = strlen(word);

    // search right
    if (c <= cols - len && !found) {
        found = true;
        for (int i = 0; i < len; i++) {
            if (!ch_equal(grid[r][c + i], word[i])) {
                found = false;
                break;
            }
        }
    }

    // search down
    if (r <= rows - len && !found) {
        found = true;
        for (int i = 0; i < len; i++) {
            if (!ch_equal(grid[r + i][c], word[i])) {
                found = false;
                break;
            }
        }
    }

    // search left
    if (c >= len-1 && !found) {
        found = true;
        for (int i = 0; i < len; i++) {
            if (!ch_equal(grid[r][c - i], word[i])) {
                found = false;
                break;
            }
        }
    }

    // search up
    if (r >= len-1 && !found) {
        found = true;
        for (int i = 0; i < len; i++) {
            if (!ch_equal(grid[r - i][c], word[i])) {
                found = false;
                break;
            }
        }
    }

    // search rightdown
    if (c <= cols - len && r <= rows - len && !found) {
        found = true;
        for (int i = 0; i < len; i++) {
            if (!ch_equal(grid[r + i][c + i], word[i])) {
                found = false;
                break;
            }
        }
    }

    // search rightup
    if (c <= cols - len && r >= len - 1 && !found) {
        found = true;
        for (int i = 0; i < len; i++) {
            if (!ch_equal(grid[r - i][c + i], word[i])) {
                found = false;
                break;
            }
        }
    }

    // search leftup
    if (c >= len-1 && r >= len - 1 && !found) {
        found = true;
        for (int i = 0; i < len; i++) {
            if (!ch_equal(grid[r - i][c - i], word[i])) {
                found = false;
                break;
            }
        }
    }

    // search leftdown
    if (c >= len-1 && r <= rows - len && !found) {
        found = true;
        for (int i = 0; i < len; i++) {
            if (!ch_equal(grid[r + i][c - i], word[i])) {
                found = false;
                break;
            }
        }
    }

    return found;
}

int main() {
    int cases, k;
    scanf("%d", &cases);

    for (int tc = 1; tc <= cases; tc++) {
        scanf("%d %d", &rows, &cols);

        for (int r = 0; r < rows; r++)
            scanf("%s", grid[r]);

        scanf("%d", &k);
        while (k-- != 0) {
            bool found = false;
            scanf("%s", word);

            for (int r = 0; r < rows && !found; r++) {
                for (int c = 0; c < cols && !found; c++) {
                    if (ch_equal(grid[r][c], word[0]) && search(r, c)) {
                        printf("%d %d\n", r+1, c+1);
                        found = true;
                    }
                }
            } 
        }

        if (tc != cases)
            printf("\n");
    }
    return 0;
}