#include <iostream>

using namespace std;

int main() {
    int n, p, tc = 0;

    while (cin >> n >> p && !(n == 0 && p == 0)) {
        if (tc != 0)
            cout << endl;

        cin.ignore();

        for (int i = 0; i < n; i++) {
            string requirement;
            getline(cin, requirement);
        }

        string best_proposal;
        double best_price = 0;
        double best_compliance = 0;

        for (int i = 0; i < p; i++) {
            string name;
            double price;
            int requirements_met;

            getline(cin, name);
            cin >> price >> requirements_met;

            cin.ignore();

            for (int r = 0; r < requirements_met; r++) {
                string requirement;
                getline(cin, requirement);
            }

            double compliance = 1.0 * requirements_met / n;

            if (compliance > best_compliance) {
                best_proposal = name;
                best_compliance = compliance;
                best_price = price;
            }
            else if (compliance == best_compliance && price < best_price) {
                best_proposal = name;
                best_price = price;
            }
        }

        cout << "RFP #" << ++tc << endl;
        cout << best_proposal << endl;
    }
    return 0;
}