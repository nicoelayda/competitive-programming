#include <iostream>
#include <vector>

using namespace std;

long long swaps = 0;

vector<long long> merge(vector<long long> left, vector<long long> right) {
    vector<long long> merged(left.size() + right.size());
    long long i = 0, li = 0, ri = 0;

    while (li != left.size() && ri != right.size()) {
        if (left[li] <= right[ri]) {
            merged[i++] = left[li++];
        }
        else {
            merged[i++] = right[ri++];
            swaps += left.size() - li;
        }
    }

    while (li != left.size()) {
        merged[i++] = left[li++];
    }

    while (ri != right.size()) {
        merged[i++] = right[ri++];
    }

    return merged;
}

vector<long long> merge_sort(vector<long long> array) {
    if (array.size() <= 1)
        return array;

    long long mid = array.size() / 2;

    vector<long long> left(array.begin(), array.begin() + mid);
    vector<long long> right(array.begin() + mid, array.end());

    return merge(merge_sort(left), merge_sort(right));
}

int main() {
    long long n;

    while (cin >> n && n != 0) {
        swaps = 0;
        vector<long long> array(n);

        for (long long i = 0; i < n; i++) {
            cin >> array[i];
        }

        array = merge_sort(array);
        cout << swaps << endl;
    }

    return 0;
}
