#include <iostream>

using namespace std;

string language_of(string s) {
    if (s == "HELLO")        return "ENGLISH";
    else if (s == "HOLA")    return "SPANISH";
    else if (s == "HALLO")   return "GERMAN";
    else if (s == "BONJOUR") return "FRENCH";
    else if (s == "CIAO")    return "ITALIAN";
    else if (s == "ZDRAVSTVUJTE") return "RUSSIAN";
    else return "UNKNOWN";
}

int main() {
    int tc = 0;
    string line;

    while (cin >> line && line != "#") {
        cout << "Case " << ++tc << ": " << language_of(line) << endl;
    }

    return 0;
}