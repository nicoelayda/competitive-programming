#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int num_heads, num_knights;
    
    while (cin >> num_heads >> num_knights) {
        if (num_heads == 0 && num_knights == 0) break;
        vector<int> heads(num_heads), knights(num_knights);

        for (int i = 0; i < num_heads; i++)
            cin >> heads[i];

        for (int i = 0; i < num_knights; i++)
            cin >> knights[i];

        if (num_knights < num_heads) {
            cout << "Loowater is doomed!" << endl;
            continue;
        }

        sort(heads.begin(), heads.end());
        sort(knights.begin(), knights.end());

        int heads_cut = 0;
        int gold = 0;
        int h = 0, k = 0;

        while (h < num_heads && k < num_knights) {
            if (heads[h] <= knights[k]) {
                heads_cut++;
                gold += knights[k];
                h++, k++;
            }
            else {
                k++;
            }
        }

        if (heads_cut == num_heads)
            cout << gold << endl;
        else
            cout << "Loowater is doomed!" << endl;
    }
    return 0;
}