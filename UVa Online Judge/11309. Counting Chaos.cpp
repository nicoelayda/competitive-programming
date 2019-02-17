#include <cstdio>

using namespace std;

bool is_palindrome(int n) {
    int original = n;
    int reverse = 0;

    while (n != 0) {
        reverse = reverse * 10 + n % 10;
        n /= 10;
    }

    return original == reverse;
}

void next_time(int &h, int &m) {
    if (++m == 60) {
        h++;
        m = 0;
    }

    if (h == 24)
        h = 0;
}

int main() {
    int T;
    scanf("%d", &T);

    int h, m;
    while (T-- != 0) {
        scanf("%d:%d", &h, &m);
        
        do {
            next_time(h, m);    
        } while (!is_palindrome(h * 100 + m));
        
        printf("%02d:%02d\n", h, m);
    }

    return 0;
}