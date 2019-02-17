#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct line {
    int left, right;

    line(int left, int right) {
        this->left = left;
        this->right = right;
    }
    
    bool operator< (const line &other) const {
        if (this->left == other.left)
            return this->right > other.right;

        return this->left < other.left;
    }
};

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        int length;
        cin >> length;

        int l, r;
        vector<line> lines;

        while (cin >> l >> r && !(l == 0 && r == 0))
            lines.push_back(line(l, r));

        sort(lines.begin(), lines.end());

        int i = 0;
        int covered = 0;
        vector<line> used;

        while (covered < length) {
            int max_reach = covered;
            line *best_line = nullptr;

            while (i < lines.size() && lines[i].left <= covered) {
                if (lines[i].right > max_reach) {
                    max_reach = lines[i].right;
                    best_line = &lines[i];
                }

                i++;
            }

            if (best_line != nullptr) {
                used.push_back(*best_line);
                covered = best_line->right;    
            } 
            else {
                break;
            }
        }

        if (covered < length) {
            cout << "0" << endl;
        }
        else {
            cout << used.size() << endl;
            for (int i = 0; i < used.size(); i++) {
                cout << used[i].left << " " << used[i].right << endl;
            }
        }

        if (T != 0) cout << endl;
    }

    return 0;
}