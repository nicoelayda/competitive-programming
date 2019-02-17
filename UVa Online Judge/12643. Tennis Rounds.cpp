#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int rounds, p1, p2;

    while (cin >> rounds >> p1 >> p2) {
        int round_num = 1;
        
        if (p1 > p2) 
            swap(p1, p2);

        while (!(p2 - p1 == 1 && p1 % 2 == 1 && p2 % 2 == 0)) {
            round_num++;

            if (p1 % 2 != 0) p1++;
            if (p2 % 2 != 0) p2++;

            p1 /= 2;
            p2 /= 2;
        }

        cout << round_num << endl;
    }

    return 0;
}