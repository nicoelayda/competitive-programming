#include <iostream>
#include <algorithm>
#include <set>
#include <cstdio>
#include <cmath>

using namespace std;

struct agency {
    string name;
    int cost;

    agency(string name, int cost) {
        this->name = name;
        this->cost = cost;
    }

    bool operator< (const agency &other) const {
        if (this->cost == other.cost)
            return this->name < other.name;
        return this->cost < other.cost;
    }
};

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int workload, target, num_agencies;
        cin >> workload >> target >> num_agencies;
        cin.ignore();

        set<agency> agencies;

        while (num_agencies-- != 0) {
            char name[128];
            int a, b, total_cost = 0;

            scanf("%[^:]:%d,%d\n", name, &a, &b);

            int remaining = workload;

            while (remaining != target) {
                double cost_per_unit_b = b / ceil(remaining / 2.0);
                
                if (cost_per_unit_b <= a && remaining / 2 >= target) {
                    remaining /= 2;
                    total_cost += b;
                }
                else {
                    remaining -= 1;
                    total_cost += a;
                }
            }

            agencies.insert(agency(string(name), total_cost));
        }

        cout << "Case " << tc << endl;
        
        set<agency>::iterator it;
        for (it = agencies.begin(); it != agencies.end(); it++)
            cout << it->name << " " << it->cost << endl;
    }

    return 0;
}