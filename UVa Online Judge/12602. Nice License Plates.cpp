#include <cstdio>
#include <cmath>

using namespace std;

int b26_to_dec(char b26str[8]) {
    int dec = 0;

    for (int i = 2, e = 0; i >= 0; i--)
        dec += (b26str[i] - 'A') * pow(26, e++);

    return dec;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T-- != 0) {
        char first[8];
        int second;

        scanf("%3s-%d", first, &second);

        if (abs(b26_to_dec(first) - second) <= 100)
            printf("nice\n");
        else
            printf("not nice\n");
        
    }

    return 0;
}