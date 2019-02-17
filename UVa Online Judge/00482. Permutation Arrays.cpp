#include <iostream>
#include <algorithm>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T-- != 0) {
        cin.ignore(1024, '\n');

        string line;
        vector<int> order;
        vector< pair<int, string> > arr;

        getline(cin, line);
        istringstream iss1(line);

        int pos;
        while (iss1 >> pos)
            order.push_back(pos);

        getline(cin, line);
        istringstream iss2(line);

        string val;
        for (int i = 0; i < order.size(); i++) {
            iss2 >> val;
            arr.push_back(make_pair(order[i], val));
        }

        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i].second << endl;
        }

        if (T != 0)
            cout << endl;
    }

    return 0;
}