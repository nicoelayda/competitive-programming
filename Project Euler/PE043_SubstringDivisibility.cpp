#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdlib>

using namespace std;

int div_table[7] = {2, 3, 5, 7, 11, 13, 17};

bool pandigital(string str) {
    for (int i = 1; i < str.length() - 2; i++) {
        if (atoi(str.substr(i, 3).c_str()) % div_table[i-1] != 0)
            return false;
    }
    return true;
}

int main() {
    long long num, sum = 0;
    string s = "0123456789";

    do {
        if (pandigital(s)) {
            stringstream(s) >> num;
            sum += num;
        }
    } while (next_permutation(s.begin(), s.end()));

    cout << sum << endl;
    return 0;
}