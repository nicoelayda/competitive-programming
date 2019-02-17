#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int z, i, m, l, n, case_num = 0;

    while (cin >> z >> i >> m >> l && (z != 0 || i != 0 || m != 0 || l != 0)) {
        bool num_used[10000];
        memset(num_used, false, sizeof(num_used));
        int seq_length = 0;
        n = l;
        do {
            if (n < m)
                num_used[n] = true;
            n = (z * n + i) % m;
            seq_length++;
        } while (!num_used[n]);

        if (n != l)
            seq_length -= 1;

        cout << "Case " << ++case_num << ": " << seq_length << endl;

    }
    return 0;
}