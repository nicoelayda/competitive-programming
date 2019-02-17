#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int main() {
    int N;

    while (cin >> N && N != 0) {
        string line;
        cin.ignore();
        
        while (getline(cin, line) && line != "0") {
            int next;
            istringstream iss(line);
            stack<int> station, buffer;

            for (int i = N; i >= 1; i--)
                station.push(i);

            while (iss >> next) {
                if (!buffer.empty() && buffer.top() == next) {
                    buffer.pop();
                }
                else if (station.empty()) {
                    break;
                }
                else {
                    while (!station.empty()) {
                        if (station.top() == next) {
                            station.pop();
                            break;
                        }
                        else {
                            buffer.push(station.top());
                            station.pop();
                        }
                    }
                }
            }

            cout << (station.empty() && buffer.empty() ? "Yes" : "No") << endl;
        }

        cout << endl;
    }

    return 0;
}