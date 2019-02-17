#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    int tc = 0;
    int a, b;

    while (cin >> a >> b) {
        if (a == -1 && b == -1)
            break;

        set<int> nodes;
        map<int, int> in_degree;
        map<int, int> out_degree;
        map<int, int> root;

        int roots_found = 0;
        bool tree = true;

        if (a == 0 && b == 0) {
            roots_found++;
            tree = true;
        }
        else {
            do {    
                nodes.insert(a);
                nodes.insert(b); 

                out_degree[a]++; 
                in_degree[b]++;
                
                if (root[a] == 0)
                    root[a] = a;
                root[b] = root[a];   
                
                if (a == b)
                    tree = false;
            } while (cin >> a >> b && a != 0 && b != 0);

            set<int>::iterator it;
            for (it = nodes.begin(); it != nodes.end(); ++it) {
                if (*it == root[*it])
                    roots_found++;
                
                if (in_degree[*it] > 1 || roots_found > 1 || (*it == root[*it] && in_degree[*it] != 0)) {
                    tree = false;
                    break;
                }
            }
        }

        if (roots_found == 1 && tree)
            cout << "Case " << ++tc << " is a tree." << endl;
        else
            cout << "Case " << ++tc << " is not a tree." << endl;

    }

    return 0;
}