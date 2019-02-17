#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct box {
    int index;
    vector<int> measurements;

    box(int index, int dimensions) {
        this->index = index;
        this->measurements = vector<int>(dimensions);
    }

    bool operator< (const box &other) const {
        for (int i = 0; i < this->measurements.size(); i++) {
            if (this->measurements[i] == other.measurements[i])
                continue;
            else
                return this->measurements[i] < other.measurements[i];
        }

        return false;
    }

    bool nests(const box &other) {
        for (int i = 0; i < this->measurements.size(); i++) {
            if (this->measurements[i] >= other.measurements[i])
                return false;
        }

        return true;
    }
};

string backtrack(vector<box> &boxes, vector<int> &prev, int end) {
    if (prev[end] == -1)
        return to_string(boxes[end].index);
    
    return backtrack(boxes, prev, prev[end]) + " " + to_string(boxes[end].index);
}

int main() {
    int k, n;

    while (cin >> k >> n) {
        vector<box> boxes;

        for (int i = 1; i <= k; i++) {
            box b(i, n);

            for (int j = 0; j < n; j++)
                cin >> b.measurements[j];

            sort(b.measurements.begin(), b.measurements.end(), greater<int>());

            boxes.push_back(b);
        }

        sort(boxes.begin(), boxes.end());

        vector<int> lcs(k, 1);
        vector<int> prev(k, -1);

        int max_length = 1;
        int end = 0;

        for (int i = 1; i < k; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (lcs[j] + 1 > lcs[i] && boxes[j].nests(boxes[i])) {
                    lcs[i] = lcs[j] + 1;
                    prev[i] = j;
                }
            }

            if (lcs[i] > max_length) {
                max_length = lcs[i];
                end = i;
            }
        }

        cout << max_length << endl;
        cout << backtrack(boxes, prev, end) << endl;
    }

    return 0;
}