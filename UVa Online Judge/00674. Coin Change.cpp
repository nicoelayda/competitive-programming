#include <iostream>
#include <algorithm>

using namespace std;

int values[5] = {1, 5, 10, 25, 50};
unsigned long long lookup[7490];

int main() {
    fill(lookup, lookup + sizeof(lookup)/sizeof(unsigned long long), 0);
    lookup[0] = 1;

    for (int i = 0; i < 5; i++) {
        for (int j = values[i]; j < 7490; j++) {
            lookup[j] += lookup[j - values[i]];
        }
    }

    int n;
    while (cin >> n)
        cout << lookup[n] << endl;

    return 0;
}