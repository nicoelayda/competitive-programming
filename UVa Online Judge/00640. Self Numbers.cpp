#include <iostream>
#include <vector>

using namespace std;

int d(int n) {
    int digit_sum = n;

    while (n != 0) {
        digit_sum += n % 10;
        n /= 10;
    }

    return digit_sum;
}

int main() {
    vector<bool> self_number(1000001, true);
    self_number[0] = false;

    for (int i = 1; i <= 1000000; i++) {
        int num = d(i);
        if (num <= 1000000)
            self_number[num] = false;

        if (self_number[i])
            cout << i << endl;
    }

    return 0;
}