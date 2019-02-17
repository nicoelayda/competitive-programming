#include <iostream>

using namespace std;

int digit_sum(int n) {
    if (n < 10)
        return n;

    int sum;

    while (n >= 10) {
        sum = 0;

        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }

        n = sum;
    }

    return sum;
}

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        string credit_card = "";

        for (int i = 0; i < 4; i++) {
            string section;
            cin >> section;
            credit_card += section;
        }

        int sum = 0;
        for (int i = 0; i < credit_card.length(); i++) {
            if (i % 2 == 0) {
                sum += digit_sum((credit_card[i] - '0') * 2);
            }
            else {
                sum += credit_card[i] - '0';
            }
        }

        cout << (sum % 10 == 0 ? "Valid" : "Invalid") << endl;

    }
    return 0;
}