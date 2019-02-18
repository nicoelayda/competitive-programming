#include <iostream>

using namespace std;

bool is_palindrome(string str) {
    int len = str.length();
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }

    return true;
}

bool is_palindrome(int n) {
    int orig = n;
    int reversed = 0;

    while (n != 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }

    return orig == reversed;
}

string binary_str(int n) {
    if (n == 0) return "0";
    if (n == 1) return "1";

    return binary_str(n / 2) + (n % 2 == 0 ? "0" : "1");
}

int main() {
    long long sum = 0;

    for (int i = 1; i < 1000000; i += 2) {
        if (is_palindrome(i) && is_palindrome(binary_str(i))) {
            sum += i;
        }
    }

    cout << sum << endl;

    return 0;
}