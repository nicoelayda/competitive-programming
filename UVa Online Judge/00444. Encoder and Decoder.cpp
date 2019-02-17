#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

string reverse_int(int n) {
    ostringstream oss;
    oss << n;

    string str = oss.str();
    reverse(str.begin(), str.end());

    return str;
}

int to_int(const string &str) {
    int n;
    istringstream(str) >> n;

    return n;
}

string to_alpha(const string &str) {
    string alpha = "";
    string ascii = "";

    for (int i = str.length() - 1; i >= 0; i--) {
        ascii += str[i];
        int ascii_val = to_int(ascii);

        if (ascii_val >= 32 && ascii_val <= 122) {
            alpha += ((char) ascii_val);
            ascii = "";
        }
    }

    return alpha;
}

string to_ascii(const string &str) {
    ostringstream oss;

    for (int i = str.length() - 1; i >= 0; i--)
        oss << reverse_int(int(str[i]));

    return oss.str();
}

int main() {
    string line;

    while (getline(cin, line)) {
        
        if (line[0] >= '0' && line[0] <= '9')
            cout << to_alpha(line) << endl;
        else
            cout << to_ascii(line) << endl;
    }

    return 0;
}