#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        int days, parties;
        cin >> days >> parties;

        vector<int> hartal_parameter(parties);
        vector<int> next_hartal(parties);
        
        for (int i = 0; i < parties; i++) {
            cin >> hartal_parameter[i];
            next_hartal[i] = hartal_parameter[i] - 1;
        }

        vector<int> hartals(7, 0);

        for (int i = 0; i < days; i++) {
            int day_of_week = i % 7;
            bool considered = false;

            for (int j = 0; j < parties; j++) {
                if (next_hartal[j] == i) {
                    next_hartal[j] += hartal_parameter[j];
                    considered = true;
                }
            }

            // not friday or saturday
            if (considered && day_of_week != 5 && day_of_week != 6) {
                hartals[day_of_week]++;
            }
        }

        cout << accumulate(hartals.begin(), hartals.end(), 0) << endl;
    }

    return 0;
}