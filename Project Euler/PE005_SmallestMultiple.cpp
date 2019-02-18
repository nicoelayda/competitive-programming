/* Project Euler
 * Problem 5 - Smallest multiple
 * Completed on Tue, 2 Apr 2013, 01:19
 */
 
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    int n = 1;
    for (int i = 2; i <= 20; i++)
        n = lcm(n, i);

    cout << n << endl;
    return 0;
}