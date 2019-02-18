#include <iostream>

using namespace std;

string tens[10] = {
    "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

string ones[20] = {
    "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
    "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

string to_number_word(int n) {
    string word = "";
    if (n == 1000) {
        return "onethousand";
    }

    // get last two digits if teens or less
    else if (n % 100 < 20) { 
        word = ones[n % 100];
        n /= 100;
    }
    // last two digits 20 - 99
    else {
        // get ones word
        word = ones[n % 10];
        n /= 10;

        // get tens word
        word = tens[n % 10] + word;
        n /= 10;
    }
    
    // get hundreds word
    if (n != 0) {
        word = ones[n] + "hundred" + (word.length() != 0 ? "and" : "") + word;   
    }

    return word;
}

int main() {
    int letters = 0;
    for (int i = 1; i <= 1000; i++)
        letters += to_number_word(i).length();

    cout << letters << endl;

    return 0;
}