#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int gcd (int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T-- != 0) {
        string line;
        getline(cin, line);

        stringstream data_string(line);
        vector<int> data_set;
        
        int n;

        while (data_string >> n)
            data_set.push_back(n);

        int max_gcd = 1;

        for (int i = 0; i < data_set.size() - 1; i++) {
            for (int j = i + 1; j < data_set.size(); j++) {
                max_gcd = max(max_gcd, gcd(data_set[i], data_set[j]));
            }
        }

        cout << max_gcd << endl;
    }
}