#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, d;

    while (cin >> n >> d) {
        vector<int> seq;

        do {
            seq.push_back(n / d);
            
            n = n % d;
            swap(n, d);

        } while (d != 0);
        

        for (int i = 0; i < seq.size(); i++) {
            if (i == 0)
                cout << "[";

            cout << seq[i];

            if (i == 0)
                cout << ";";
            else if (i == seq.size() - 1)
                cout << "]" << endl;
            else
                cout << ",";
        }
    }


    return 0;
}