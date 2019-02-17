#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        int n, m;
        cin >> n >> m;

        vector<int> list1(n);
        vector<int> list2(m);

        for (int i = 0; i < n; i++)
            cin >> list1[i];
        for (int i = 0; i < m; i++)
            cin >> list2[i];

        sort(list1.begin(), list1.end());
        sort(list2.begin(), list2.end());

        int removed = 0;

        int i1 = 0, i2 = 0;

        while (i1 != list1.size() && i2 != list2.size()) {
            if (list1[i1] == list2[i2]) {
                i1++, i2++;
            }
            else if (list1[i1] < list2[i2]) {
                removed++;
                i1++;
            }
            else if (list1[i1] > list2[i2]) {
                removed++;
                i2++;
            }
        }

        removed += list1.size() - i1;
        removed += list2.size() - i2;

        cout << removed << endl;
    }
    return 0;
}