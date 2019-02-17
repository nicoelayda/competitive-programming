#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int n, tc = 0;

    while (cin >> n) {
        int s[n];

        for (int i = 0; i < n; i++)
            cin >> s[i];

        long long product, max_product = 0;
        for (int i = 0; i < n; i++) {
            product = s[i];
            max_product = max(product, max_product);

            for (int j = i + 1; j < n; j++) {
                product *= s[j];
                max_product = max(product, max_product);
            }
        }

        cout << "Case #" << ++tc << ": The maximum product is " << max_product << "." << endl << endl;
    }    

    return 0;
}