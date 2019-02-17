#include <cstdio>
#include <queue>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

struct state {
    vector<int> jugs;
    int poured;

    state(int a, int b, int c, int p) {
        this->poured = p;
        this->jugs.push_back(a);
        this->jugs.push_back(b);
        this->jugs.push_back(c);
    }

    state(const state &s) : jugs(s.jugs) {
        this->poured = s.poured;
    }
};

string config(int a, int b, int c) {
    stringstream sstr;
    sstr << a << " " << b << " " << c;
    return sstr.str();
}

int main() {
    int T;
    scanf("%d", &T);

    while (T-- != 0) {
        int limits[3], d;
        scanf("%d %d %d %d", &limits[0], &limits[1], &limits[2], &d);

        queue<state> fringe;
        set<string> used_configurations; // visited nodes, O(log n) check time
        
        fringe.push(state(0, 0, limits[2], 0));
        used_configurations.insert(config(0, 0, limits[2]));

        int poured = 0;
        int liters = 0;

        while (!fringe.empty()) {
            state curr = fringe.front(); fringe.pop();

            // goal state
            if (curr.jugs[0] == d || curr.jugs[1] == d || curr.jugs[2] == d) {
                poured = curr.poured;
                liters = d;
                break;
            }
            // if not goal, calculate local optimum
            else {
                for (int i = 0; i < 3; i++) {
                    if (curr.jugs[i] < d && d - curr.jugs[i] < d - liters) {
                        poured = curr.poured;
                        liters = curr.jugs[i];
                    }
                }
            }

            for (int i = 0; i < 3; i++) {
                // if jug is not empty
                if (curr.jugs[i] != 0) {
                    for (int j = 0; j < 3; j++) {

                        // if not pouring to self AND not pouring to a full jug
                        if (i != j && curr.jugs[j] != limits[j]) {
                            // create state copy "next"
                            state next(curr);
                            int diff = min(limits[j] - curr.jugs[j], curr.jugs[i]);

                            next.jugs[i] -= diff;
                            next.jugs[j] += diff;
                            next.poured += diff;

                            string config_str = config(next.jugs[0], next.jugs[1], next.jugs[2]);

                            // check if configuration has already been used
                            if (used_configurations.find(config_str) == used_configurations.end()) {
                                fringe.push(next);    
                                used_configurations.insert(config_str); // mark this configuration as used (visited)
                            }
                        }
                    }
                }
            }
        }

        printf("%d %d\n", poured, liters);
    }

    return 0;
}