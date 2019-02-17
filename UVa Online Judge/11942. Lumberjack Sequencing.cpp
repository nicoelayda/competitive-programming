#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    cout << "Lumberjacks:" << endl;

    while (T-- != 0) {
        int lumberjacks[10];
        
        for (int i = 0; i < 10; i++)
            cin >> lumberjacks[i];

        int order = 0;
        bool ordered = true;
        for (int i = 0; i < 9 && ordered; i++) {
            switch (order) {
                case -1: // descending
                    if (lumberjacks[i] - lumberjacks[i + 1] > 0)
                        ordered = false;
                    break;

                case 1: // ascending
                    if (lumberjacks[i] - lumberjacks[i + 1] < 0)
                        ordered = false;
                    break;

                default: // unknown
                    if (lumberjacks[i] - lumberjacks[i + 1] < 0)
                        order = -1;
                    else if (lumberjacks[i] - lumberjacks[i + 1] > 0)
                        order = 1;
            }
        }

        cout << (ordered ? "Ordered" : "Unordered") << endl;
    }
    return 0;
}