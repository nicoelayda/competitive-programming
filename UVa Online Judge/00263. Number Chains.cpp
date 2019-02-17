#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;

string to_string(int n) {
    ostringstream sstr;
    sstr << n;
    return sstr.str();
}

int to_int(string str) {
    int n;
    istringstream(str) >> n;
    return n;
}

int main() {
    string num;

    while (cin >> num && num != "0") {
        set<string> used;

        cout << "Original number was " << num << endl;
        
        while (used.find(num) == used.end()) {
            used.insert(num);
            
            sort(num.begin(), num.end());
            
            int asc = to_int(num);
            int desc = to_int(string(num.rbegin(), num.rend()));

            num = to_string(desc - asc);
            cout << desc << " - " << asc << " = " << num << endl;
        }
        
        cout << "Chain length " << used.size() << endl << endl;
    }

    return 0;
}