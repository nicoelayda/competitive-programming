#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, r;

    while (cin >> n >> r) {
        if (n == r) {
            for (int temp, i = 0; i < r; i++)
                cin >> temp;

            cout << "*" << endl;
        }
        else {
            set<int> volunteers;
            for (int i = 1; i <= n; i++)
                volunteers.insert(i);

            for (int temp, i = 0; i < r; i++) {
                cin >> temp;
                volunteers.erase(temp);
            }

            set<int>::iterator it;
            for (it = volunteers.begin(); it != volunteers.end(); ++it)
                cout << *it << " ";

            cout << endl;
        }
    }

    return 0;
}