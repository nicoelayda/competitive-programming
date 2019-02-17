#include <iostream>
#include <set>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int n;
        set<int> used;

        cin >> n;        
        cout << "Case #" << tc << ": " << n;

        for (int i = 2, pairs = 0; i < n && pairs < 2; i++) {
            if (n % i == 0 && used.find(i) == used.end()) {
                int res = n / i;
                if (used.find(res) == used.end()) {
                    cout << " = " << i << " * " << res;
                    
                    used.insert(i);
                    used.insert(res);
                    pairs++;
                }
            }
        }
        cout << endl;

    }

    return 0;
}