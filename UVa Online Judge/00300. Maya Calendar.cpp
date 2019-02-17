#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const string month_names[] = {
    "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", 
    "mol", "chen", "yax", "zac", "ceh", "mac", 
    "kankin", "muan", "pax", "koyab", "cumhu", "uayet"
};

const string day_names[] = {
    "imix", "ik", "akbal", "kan", "chicchan", 
    "cimi", "manik", "lamat", "muluk", "ok", 
    "chuen", "eb", "ben", "ix", "mem", 
    "cib", "caban", "eznab", "canac", "ahau"
};

int main() {
    int T;
    cin >> T;
    cout << T << endl;

    int d, m, y;
    char month[128];

    while (T-- != 0) {
        scanf("%d. %[^ ] %d", &d, month, &y);
        m = distance(month_names, find(month_names, month_names + 18, month));
        
        int total_days = 365 * y + 20 * m + d;
        int year = total_days / 260;

        cout << total_days % 13 + 1 << " " << day_names[total_days % 20] << " " << year << endl;
    }

    return 0;
}