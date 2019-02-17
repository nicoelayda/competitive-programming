#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int s, tc = 0;

    while (cin >> s && s >= 0) {
        vector<int> problems_available(12, 0);
        
        int total_problems = s;

        cout << "Case " << ++tc << ":" << endl;

        for (int i = 0; i < 12; i++) {
            int new_problems;
            cin >> new_problems;

            problems_available[i] = total_problems;
            total_problems += new_problems;
        }

        for (int i = 0; i < 12; i++) {
            int required_problems;
            cin >> required_problems;

            if (required_problems <= problems_available[i]) {
                cout << "No problem! :D" << endl;
                for (int j = i; j < 12; j++) {
                    problems_available[j] = max(0, problems_available[j] - required_problems);
                }
            }
            else
                cout << "No problem. :(" << endl;
        }
    }


    return 0;
}