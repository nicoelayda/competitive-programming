#include <iostream>
#include <map>

using namespace std;

int main() {
    int duration, num_records;
    double down_payment, loan;

    while (cin >> duration >> down_payment >> loan >> num_records && duration >= 0) {
        int month;
        double val;
        map<int, double> dep_records;
        
        for (int i = 0; i < num_records; i++) {
            cin >> month >> val;
            dep_records[month] = val;
        }

        double car_value, dep_value;
        double monthly_pay = loan / duration;

        for (int i = 0; i <= duration; i++) {
            if (dep_records.find(i) != dep_records.end())
                dep_value = dep_records[i];
            
            if (i == 0) {
                car_value = (loan + down_payment) * (1.0 - dep_value);
            } 
            else {
                loan -= monthly_pay;
                car_value -= car_value * dep_value;    
            }
            
            if (loan < car_value) {
                cout << i << (i == 1 ? " month" : " months") << endl;
                break;
            }
        }
    }
    return 0;
}