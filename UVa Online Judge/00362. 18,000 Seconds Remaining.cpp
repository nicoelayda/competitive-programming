#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int file_size, tc = 0;

    while (cin >> file_size && file_size != 0) {
        int t = 0;
        int transferred_total = 0;
        int transferred_1s, transferred_5s = 0;

        cout << "Output for data set " << ++tc << ", " << file_size << " bytes:" << endl;

        do {
            t++;
            cin >> transferred_1s;
            transferred_5s += transferred_1s;
            transferred_total += transferred_1s;

            if (t % 5 == 0) {
                if (transferred_5s == 0) {
                    cout << "   Time remaining: stalled" << endl;
                }
                else {
                    double transfer_rate = transferred_5s * 0.2;
                    int time_remaining = ceil((file_size - transferred_total) / transfer_rate);
                    cout << "   Time remaining: " << time_remaining << " seconds" << endl;
                }

                transferred_5s = 0;
            }
        } while (transferred_total < file_size);

        cout << "Total time: " << t << " seconds" << endl << endl;
    }
    
    return 0;
}