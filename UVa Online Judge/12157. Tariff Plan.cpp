#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;

        vector<int> mile_cost(N);
        vector<int> juice_cost(N);

        for (int i = 0; i < N; i++) {
            int call;
            cin >> call;

            call += 1;

            mile_cost.push_back(call % 30 == 0 ? call / 30 * 10 : (call / 30 + 1) * 10);
            juice_cost.push_back(call % 60 == 0 ? call / 60 * 15 : (call / 60 + 1) * 15);
        }

        int mile = accumulate(mile_cost.begin(), mile_cost.end(), 0);
        int juice = accumulate(juice_cost.begin(), juice_cost.end(), 0);

        cout << "Case " << tc << ": "
             << (mile <= juice ? "Mile " : "")
             << (juice <= mile ? "Juice " : "")
             << min(mile, juice) << endl;


    }
    return 0;
}