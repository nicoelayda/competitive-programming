#include <iostream>
#include <sstream>

using namespace std;

string int_to_str(int n) {
    stringstream sstr;
    sstr << n;
    return sstr.str();
}

int main() {
    string x;

    while (cin >> x && x != "END") {
        int i = 0;
        string last = "";

        while (x != last) {
            i++;
            last = x;
            x = int_to_str(last.length());
        }

        cout << i << endl;
    }

    return 0;
}