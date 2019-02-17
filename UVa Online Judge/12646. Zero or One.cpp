#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    
    while (cin >> a >> b >> c) {
        if (b == c && a != b) {
            cout << "A" << endl;
        }
        else if (a == c && a != b) {
            cout << "B" << endl;
        }
        else if (a == b && a != c) {
            cout << "C" << endl;
        }
        else {
            cout << "*" << endl;
        }
        

    }
    return 0;
}