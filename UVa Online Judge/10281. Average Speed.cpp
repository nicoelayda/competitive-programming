#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    char line[1024];
    int speed = 0;
    int distance = 0;
    int elapsed_time = 0;

    while (cin.getline(line, sizeof(line))) {
        int h, m, s;
        int curr_time;

        if (strlen(line) == 8) {
            sscanf(line, "%d:%d:%d", &h, &m, &s);
           
            curr_time = h * 3600 + m * 60 + s;
            distance += speed * (curr_time - elapsed_time);

            printf("%02d:%02d:%02d %.2lf km\n", h, m, s, distance / 3600.0);

            elapsed_time = curr_time;
        }
        else {
            int new_speed;
            sscanf(line, "%d:%d:%d %d", &h, &m, &s, &new_speed);

            curr_time = h * 3600 + m * 60 + s;
            distance += speed * (curr_time - elapsed_time);

            speed = new_speed;
            elapsed_time = curr_time;
        }
    }


    return 0;
}