#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int n, card, max_elem = 0;
        cin >> n;

        while (n-- != 0) {
            cin >> card;
            max_elem = max(max_elem, card);  
        }

        cout << "Case " << tc << ": " << max_elem << endl;
        
    }   
    return 0;
}