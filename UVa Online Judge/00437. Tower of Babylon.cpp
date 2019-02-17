#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

struct block {
    int l, w, h;

    block(int h, int l, int w) {
        this->h = h; 
        this->l = min(l, w);
        this->w = max(l, w);
    }

    bool operator< (const block &other) const {
        return (this->l < other.l && this->w < other.w) || (this->l < other.w && this->w < other.l);
    }
};

bool height_comparator(block a, block b) {
    if (a.l != b.l) 
        return (a.l < b.l);
    else if (a.w != b.w) 
        return (a.w < b.w); 
    else 
        return (a.h < b.h);
}

int main() {
    int n, tc = 0;

    while (cin >> n && n != 0) {
        vector<block> blocks;
        int x, y, z;

        while (n-- != 0) {
            cin >> x >> y >> z;
            blocks.push_back(block(x, y, z));
            blocks.push_back(block(y, x, z));
            blocks.push_back(block(z, x, y));
        }

        sort(blocks.begin(), blocks.end(), height_comparator);   

        int max_height = numeric_limits<int>::min();
        vector<int> lis(blocks.size());

        for (int i = 0 ; i < blocks.size(); i++) {
            lis[i] = blocks[i].h;

            for (int j = i - 1; j >= 0 ; j--) {
                if (blocks[j] < blocks[i]) {
                    lis[i] = max (lis[i], lis[j] + blocks[i].h);
                }
            }
            max_height = max (lis[i] , max_height);
        }

        cout << "Case " << ++tc << ": maximum height = " << max_height << endl;
    }
    return 0;
}