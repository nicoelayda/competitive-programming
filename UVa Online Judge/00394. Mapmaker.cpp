#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

struct array_definition {
    string name;
    int base_address;
    int elem_size;
    int dimension;
    vector<int> l_bounds;
    vector<int> u_bounds;
};

string list_indices(int index_list[], int size) {
    stringstream index_string; 
    index_string << "[";

    for (int i = 0; i < size; i++) {
        if (i != 0)
            index_string << ", ";
        index_string << index_list[i];
    }

    index_string <<  "]";
    return index_string.str();
}

int physical_address(array_definition def, int index_list[]) {
    int address = 0;
    int c[def.dimension + 1];

    c[def.dimension] = def.elem_size;
    c[0] = def.base_address - (c[def.dimension] * def.l_bounds[def.dimension - 1]);

    for (int d = def.dimension - 1; d > 0; d--) {
        c[d] = c[d+1] * (def.u_bounds[d] - def.l_bounds[d] + 1);
        c[0] -= (c[d] * def.l_bounds[d-1]);
    }

    address = c[0];
    for (int i = 1; i <= def.dimension; i++) {
        address += c[i] * index_list[i-1];
    }

    return address;
}

int main() {
    int n, r, lb, ub;
    map<string, int> index_map;

    cin >> n >> r;

    array_definition defs[n];
    for (int i = 0; i < n; i++) {
        cin >> defs[i].name >> defs[i].base_address >> defs[i].elem_size >> defs[i].dimension;

        for (int j = 0; j < defs[i].dimension; j++) {
            cin >> lb >> ub;
            defs[i].l_bounds.push_back(lb);
            defs[i].u_bounds.push_back(ub);
        }

        index_map[defs[i].name] = i;
    }

    for (int i = 0; i < r; i++) {
        string name;
        cin >> name;
        
        int index_list[defs[index_map[name]].dimension];

        for (int j = 0; j < defs[index_map[name]].dimension; j++)
            cin >> index_list[j];

        cout << defs[index_map[name]].name << list_indices(index_list, defs[index_map[name]].dimension) << " = " << physical_address(defs[index_map[name]], index_list) << endl;
    }

    return 0;
}