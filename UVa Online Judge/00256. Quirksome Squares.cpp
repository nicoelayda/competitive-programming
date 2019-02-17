#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>

using namespace std;

string int_to_str(int n, int length) {
    ostringstream ss;
    ss << setfill('0') << setw(length) << n;
    return ss.str();
}

int str_to_int(string str) {
    int n;
    stringstream ss;
    ss << str;
    ss >> n;
    return n;
}

int calc_limit(int digits) {
    int limit = 0;
    for (int i = 0; i < digits; i++) {
        limit = limit * 10 + 9;
    }
    return limit;
}

bool quirksome(string str) {
    int mid = str.length() / 2;
    int n1 = str_to_int(str.substr(0, mid));
    int n2 = str_to_int(str.substr(mid, str.length()));
    
    return pow(n1 + n2, 2) == str_to_int(str);
}

int main() {
    int digits;

    while (cin >> digits) {
        int limit = calc_limit(digits);

        for (int i = 0; i*i <= limit; i++) {
            string num_string = int_to_str(i*i, digits);
            if (quirksome(num_string))
                cout << num_string << endl;
        }
    }

}