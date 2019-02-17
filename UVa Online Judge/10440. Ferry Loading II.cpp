#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        int capacity, travel_time, num_cars;
        cin >> capacity >> travel_time >> num_cars;

        queue<int> cars;

        for (int car, i = 0; i < num_cars; i++) {
            cin >> car;
            cars.push(car);
        }

        int total_time = 0;
        int trips = 0;

        while (!cars.empty()) {
            do {
                total_time = max(cars.front(), total_time);
                cars.pop();
            } while (cars.size() % capacity != 0);

            trips += 1;

            if (cars.empty())
                total_time += travel_time;
            else
                total_time += travel_time * 2;
        }

        cout << total_time << " " << trips << endl;
    }
    return 0;
}