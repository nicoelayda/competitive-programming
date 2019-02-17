#include <iostream>
#include <cmath>

using namespace std;

int main() {  
    int tc = 0;
    long long n;

    while (cin >> n && n != 0) {
        cout << "Case " << ++tc << ": " << int(ceil((3 + sqrt(9 + 8*n)) / 2)) << endl;
    }

    return 0;
}