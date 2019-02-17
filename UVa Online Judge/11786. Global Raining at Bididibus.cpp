#include <iostream>
#include <stack>

using namespace std;

int main() {
    int T;
    string line;
    cin >> T;

    while (T-- != 0) {
        stack<int> stk;
        cin >> line;

        long long water = 0;
        
        for (int i = 0; i < line.length(); i++) {
            switch (line[i]) {
                case '\\':
                    stk.push(i);
                    break;

                case '/':
                    if (!stk.empty()) {
                        water += i - stk.top();
                        stk.pop();
                    }
                    break;
            }
        }

        cout << water << endl;
    }
    return 0;
}