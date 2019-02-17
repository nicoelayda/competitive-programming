#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int n, scarecrows = 0;
        cin >> n;
        
        char field[n];
        bool is_protected[n];
        for (int i = 0; i < n; i++) {
            cin >> field[i];
            is_protected[i] = field[i] == '#' ? true : false;
        }

        for (int i = 1; i < n; i++) {
            if (!is_protected[i - 1]) {
                for (int j = i - 1; j < n && j <= i + 1; j++)
                    is_protected[j] = true;

                scarecrows++;
            }
        }

        if (is_protected[n-1] == false)
            scarecrows++;

        cout << "Case " << tc << ": " << scarecrows << endl;
    }
    return 0;
}