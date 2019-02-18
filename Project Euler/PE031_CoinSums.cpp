/* Project Euler
 * Problem 31 - Coin sums
 * Completed on Mon, 16 Dec 2013, 05:44
 */

#include <iostream>
#include <algorithm>

using namespace std;

int values[8] = {1, 2, 5, 10, 20, 50, 100, 200};
int lookup[201];

int main() {
    fill(lookup, lookup + 201, 0);
    lookup[0] = 1;

    for (int i = 0; i < 8; i++) {
        for (int j = values[i]; j <= 200; j++) {
            lookup[j] += lookup[j - values[i]];
        }
    }

    cout << lookup[200] << endl;
}