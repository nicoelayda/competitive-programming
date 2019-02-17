#include <iostream>

using namespace std;

int main() {
    int T;
    string experiment;

    cin >> T;

    while (T-- != 0) {
        cin >> experiment;
        int len = experiment.length();

        if (experiment == "1" || experiment == "4" || experiment == "78")
            cout << "+" << endl;
        else if (experiment[len - 1] == '5' && experiment[len - 2] == '3')
            cout << "-" << endl;
        else if (experiment[0] == '9' && experiment[len - 1] == '4')
            cout << "*" << endl;
        else if (experiment[0] == '1' && experiment[1] == '9' && experiment[2] == '0')
            cout << "?" << endl;
        else
            cout << "+" << endl;
    }

    return 0;
}