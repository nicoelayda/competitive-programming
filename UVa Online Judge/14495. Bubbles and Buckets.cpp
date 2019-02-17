#include <iostream>
#include <vector>

using namespace std;

int swaps = 0;

vector<int> merge(vector<int> left, vector<int> right) {
    vector<int> merged(left.size() + right.size());
    int i = 0, li = 0, ri = 0;

    while (li != left.size() && ri != right.size()) {
        if (left[li] <= right[ri]) {
            merged[i++] = left[li++];
        }
        else {
            merged[i++] = right[ri++];
            swaps += left.size() - li;
        }
    }

    while (li != left.size())
        merged[i++] = left[li++];

    while (ri != right.size())
        merged[i++] = right[ri++];

    return merged;
}

vector<int> merge_sort(vector<int> array) {
    if (array.size() <= 1)
        return array;

    int mid = array.size() / 2;

    vector<int> left(array.begin(), array.begin() + mid);
    vector<int> right(array.begin() + mid, array.end());

    return merge(merge_sort(left), merge_sort(right));
}

int main() {
    int n;

    while (cin >> n && n != 0) {
        vector<int> array(n);

        for (int i = 0; i < n; i++)
            cin >> array[i];

        swaps = 0;
        array = merge_sort(array);

        cout << (swaps % 2 == 0 ? "Carlos" : "Marcelo") << endl;
    }

    return 0;
}