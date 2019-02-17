#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int w, h, n;

    while (cin >> w >> h >> n) {
        if (w == 0 && h == 0 && n == 0)
            break;

        int empty_spots = w * h;
        vector<vector<bool> > is_empty(h, vector<bool>(w, true));

        while (n-- != 0) {
            int x1, y1, x2, y2;
            int r_lb, r_ub, c_lb, c_ub;

            cin >> x1 >> y1 >> x2 >> y2;

            r_lb = min(y1, y2);
            r_ub = max(y1, y2);
            c_lb = min(x1, x2);
            c_ub = max(x1, x2);

            for (int i = r_lb - 1; i < r_ub; i++) {
                for (int j = c_lb - 1; j < c_ub; j++) {
                    if (is_empty[i][j]) {
                        is_empty[i][j] = false;
                        empty_spots--;
                    }
                }
            }
        }

        if (empty_spots == 0)
            cout << "There is no empty spots." << endl;
        else if (empty_spots == 1)
            cout << "There is one empty spot." << endl;
        else
            cout << "There are " << empty_spots << " empty spots." << endl;

    }
    
    return 0;
}