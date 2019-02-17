#include <iostream>
#include <vector>

using namespace std;

vector<unsigned long long> count(101, 0);

int main() {
    int n;

    for (int i = 1; i <= 100; i++) {
        count[i] = i*i + count[i-1];
    }

    while (cin >> n && n != 0) {
        cout << count[n] << endl;
    }

    return 0;
}