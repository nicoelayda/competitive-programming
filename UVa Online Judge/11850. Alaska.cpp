#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int stations;

    while (scanf("%d", &stations) == 1 && stations != 0) {
        vector<bool> has_station(1423, false);
        
        while (stations-- != 0) {
            int station_num;
            scanf("%d", &station_num);
            has_station[station_num] = true;
        }

        int power = 200;
        int possible = true;
        for (int i = 1; i <= 1422 && possible; i++) {
            power--;
            if (has_station[i])
                power = 200;

            if (power == 0)
                possible = false;
        }

        for (int i = 1421; i >= 0 && possible; i--) {
            power--;
            if (has_station[i])
                power = 200;

            if (power == 0)
                possible = false;
        }

        printf("%s\n", possible ? "POSSIBLE" : "IMPOSSIBLE");
    }


}