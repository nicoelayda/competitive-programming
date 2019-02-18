#include <iostream>

using namespace std;

int main() {
    int temp, prev = 1, curr = 1;
    int sum = 0;

    while (curr < 4000000) {
        if (curr % 2 == 0)
            sum += curr;

        temp = prev + curr;
        prev = curr;
        curr = temp;
    }
    cout << sum << endl;
    return 0;
}