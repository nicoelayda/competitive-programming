#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Person {
    string name;
    int d, m, y;

    Person(string _name, int _d, int _m, int _y) {
        name = _name;
        d = _d;
        m = _m;
        y = _y;
    }
};

bool compare(Person p1, Person p2) {
    if (p1.y == p2.y) {
        if (p1.m == p2.m) {
            return p1.d < p2.d;
        }
        return p1.m < p2.m;
    }
    return p1.y < p2.y;
}

int main() {
    int n;
    vector<Person> persons;
    
    cin >> n;

    while (n-- != 0) {
        string name;
        int d, m, y;

        cin >> name >> d >> m >> y;

        persons.push_back(Person(name, d, m, y));
    }

    sort(persons.begin(), persons.end(), compare);

    cout << persons[persons.size() - 1].name << endl;
    cout << persons[0].name << endl;
    return 0;
}