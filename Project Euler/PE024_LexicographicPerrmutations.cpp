#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string num = "0123456789";

    for (int perm_count = 1; perm_count < 1000000; perm_count++)
        next_permutation(num.begin(), num.end());

    cout << num << endl;
    return 0;
}