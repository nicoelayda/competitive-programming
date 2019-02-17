#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        int num_objects;
        cin >> num_objects;

        int price[num_objects];
        int weight[num_objects];

        for (int i = 0; i < num_objects; i++)
            cin >> price[i] >> weight[i];

        int total = 0;
        int num_people;
        cin >> num_people;

        while (num_people-- != 0) {
            int max_weight;
            cin >> max_weight;

            vector < vector<int> > dp(num_objects + 1, vector<int>(max_weight + 1, 0));

            for (int i = 1; i <= num_objects; i++) {
                for (int j = 1; j <= max_weight; j++) {
                    if (weight[i - 1] <= j)
                        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + price[i - 1]);
                    else
                        dp[i][j] = dp[i - 1][j];
                }
            }

            total += dp[num_objects][max_weight];
        }

        cout << total << endl;
    }
    return 0;
}