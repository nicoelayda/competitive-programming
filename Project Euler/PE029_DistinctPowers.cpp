#include <iostream>
#include <cmath>
#include <set>

using namespace std;

int main() {
    set<double> nums;

    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {
            nums.insert(pow(a, b));
        }
    }

    cout << nums.size() << endl;
    return 0;
}