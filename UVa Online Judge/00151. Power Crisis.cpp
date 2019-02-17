#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;

    while (cin >> n && n != 0) {
        bool solved = false;
        queue<int> cities;
        
        for (int i = 1; i <= n; i++)
            cities.push(i);

        int m = 1;
        while (!solved) {
            queue<int> remaining(cities);

            while (remaining.size() > 1 && remaining.front() != 13) {
                remaining.pop();

                for (int i = 1; i < m; i++) {
                    remaining.push(remaining.front());
                    remaining.pop();
                }
            }

            if (remaining.size() == 1)
                solved = true;
            else
                m++;
        }

        cout << m << endl;
    }
    return 0;
}