#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        int money, garments_to_buy;

        while (cin >> money >> garments_to_buy) {
            vector<int> garments[garments_to_buy];

            for (int i = 0; i < garments_to_buy; i++) {
                int garment_count;
                cin >> garment_count;

                while (garment_count-- != 0) {
                    int price;
                    cin >> price;

                    garments[i].push_back(price);
                }
            }

            vector<vector<bool> > lookup(garments_to_buy, vector<bool>(money + 1, false));

            for (int i = 0; i < garments[0].size(); i++) {
                if (garments[0][i] <= money) {
                    lookup[0][garments[0][i]] = true;
                }
            }

            // create dp table
            for (int i = 1; i < garments_to_buy; i++) {
                for (int j = 0; j <= money; j++) {
                    if (lookup[i - 1][j]) {
                        for (int k = 0; k < garments[i].size(); k++) {
                            if (garments[i][k] <= money - j) {
                                lookup[i][j + garments[i][k]] = true;
                            }
                        }
                    }
                }
            }

            int max_spent = -1;
            for (int i = 0; i <= money; i++) {
                if (lookup[garments_to_buy - 1][i]) {
                    max_spent = i;
                }
            }

            if (max_spent != -1)
                cout << max_spent << endl;
            else
                cout << "no solution" << endl;
        }
    }

    return 0;
}