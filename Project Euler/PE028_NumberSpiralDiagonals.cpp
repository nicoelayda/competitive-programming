#include <iostream>

using namespace std;

int main() {
    int sum = 1;
    int jump = 0;
    int to_add = 1;
    int grid = 1001 / 2;
    
    while (grid-- > 0) {
        jump += 2;
        for (int j = 0; j < 4; j++) {
            to_add += jump;
            sum += to_add;
        }
    }

    cout << sum << endl;
    return 0;
}