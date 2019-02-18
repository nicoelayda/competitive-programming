#include <iostream>
#include <sstream>
using namespace std;

const int limit = 1000000;

int main() {
    stringstream ss;
    string champ;

    int i = 1;
    while (ss.tellp() < limit)
        ss << i++;

    champ = ss.str();

    int n = 1, product = 1;
    while (n <= limit) {
        product *= (champ[n-1] - '0');
        n *= 10;
    }
    
    cout << product << endl;
    return 0;
}