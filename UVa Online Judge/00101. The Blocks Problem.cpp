#include <iostream>
#include <deque>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int num_blocks;
    cin >> num_blocks;
    cin.ignore();

    vector< deque<int> > blocks(num_blocks);
    vector<int> block_pos(num_blocks, 0);

    for (int i = 0; i < num_blocks; i++) {
        blocks[i].push_front(i);
        block_pos[i] = i;
    }

    string command;
    while (getline(cin, command) && command != "quit") {
        string action_a, action_b; 
        int a, b;

        istringstream cmdstream(command);
        cmdstream >> action_a >> a >> action_b >> b;

        if (a == b || block_pos[a] == block_pos[b])
            continue;

        deque<int> *source = &blocks[block_pos[a]];
        deque<int> *dest = &blocks[block_pos[b]];

        if (action_a == "move") {
            while (!source->empty() && source->front() != a) {
                int block = source->front(); source->pop_front();
                blocks[block].push_front(block);
                block_pos[block] = block;
            }
        }

        if (action_b == "onto") {
            while (!dest->empty() && dest->front() != b) {
                int block = dest->front(); dest->pop_front();
                blocks[block].push_front(block);
                block_pos[block] = block;
            }
        }
        
        deque<int>::iterator it = source->begin();
        while (it != source->end()) {
            block_pos[*it] = block_pos[b];
            if (*it++ == a) break;
        }
        
        dest->insert(dest->begin(), source->begin(), it);
        source->erase(source->begin(), it);
    }

    for (int i = 0; i < num_blocks; i++) {
        cout << i << ":";
        while (!blocks[i].empty()) {
            cout << " " << blocks[i].back(); blocks[i].pop_back();
        }
        cout << endl;
    }

    return 0;
}