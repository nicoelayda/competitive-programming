#include <iostream>

using namespace std;

int main() {
    string n;
    
    while (cin >> n && n != "0") {
        int sum = 0, offset = 0;
        for (int i = 0; i < n.length(); i++) {
            if ((i+1) % 2 == 0)
                sum += (n[i] - '0');
            else
                sum -= (n[i] - '0');
        }

        cout << n << " is" << (sum % 11 == 0 ? " " : " not ")<< "a multiple of 11." << endl;
    }

    return 0;
}