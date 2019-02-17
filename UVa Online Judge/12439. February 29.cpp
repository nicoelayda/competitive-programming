#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

const int NUM_MONTHS = 12;

const string months[NUM_MONTHS] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

bool is_leap(int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

bool before_leap(int month, int day) {
    return month < 2 || (month == 2 && day < 29);
}

bool after_leap(int month, int day) {
    return month > 2;
}

int main() {
    int T;
    cin >> T;

    map<string, int> month_map;

    for (int i = 0; i < NUM_MONTHS; i++) {
        month_map[months[i]] = i + 1;
    }

    for (int tc = 1; tc <= T; tc++) {
        char from_month_name[256], to_month_name[256];
        int from_day, from_year;
        int to_day, to_year;

        scanf("%s %d, %d", from_month_name, &from_day, &from_year);
        scanf("%s %d, %d", to_month_name, &to_day, &to_year);

        int from_month = month_map[from_month_name];
        int to_month = month_map[to_month_name];

        int leap = 0;

        if (after_leap(from_month, from_day))
            from_year += 1;

        if (before_leap(to_month, to_day))
            to_year -= 1;

        leap += to_year / 4 - (from_year - 1) / 4;
        leap -= to_year / 100 - (from_year - 1) / 100;
        leap += to_year / 400 - (from_year - 1) / 400;

        cout << "Case " << tc << ": " << leap << endl;

    }

    return 0;
}