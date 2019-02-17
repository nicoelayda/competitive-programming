#include <iostream>
#include <string>

using namespace std;

int deg;

string reduce(string num) {
    int digit_sum = 0;
    deg += 1;
    
    for (int i = 0; i < num.length(); i++)
        digit_sum += int(num[i] - '0');
        
    if (digit_sum < 10)
        return to_string(digit_sum);
        
    return reduce(to_string(digit_sum));
}

int main() {
    string line;
    
    while (getline(cin, line) && line != "0") {
        deg = 0;
        string last_digit = reduce(line);
        
        if (last_digit == "9")
            cout << line << " is a multiple of 9 and has 9-degree " << deg << "." << endl;
        else
            cout << line << " is not a multiple of 9." << endl;
    }
    
    return 0;
}