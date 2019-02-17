#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>

using namespace std;

struct node {
    // amino acid sequence
    vector< set<char> > acids;

    // constructor, initialize n acid elements
    node(int n) {
        acids = vector< set<char> >(n);
    }
};

int main() {
    int n, len;

    while (cin >> n >> len && (n + len) != 0) {
        string amino_sequence;
        queue<node> nodes;

        // Parse input
        for (int i = 0; i < n; i++) {
            cin >> amino_sequence;
            node new_node(len);

            for (int j = 0; j < amino_sequence.length(); j++) {
                new_node.acids[j].insert(amino_sequence[j]);
            }

            nodes.push(new_node);
        }

        // Total tree cost, initially set to 0
        int cost = 0;

        // Keep deriving the parent until there is only 1 node left
        while (nodes.size() != 1) {
            node left = nodes.front(); nodes.pop();
            node right = nodes.front(); nodes.pop();

            node parent(len);

            // For each set of amino acids at position i, get the INTERSECTION of 
            // left.acids[i] and right.acids[i] and assign it to parent.acids[i].
            // If the intersection yields an empty set, get the UNION instead, and
            // increment the total cost of the tree by 1
            for (int i = 0; i < parent.acids.size(); i++) {
                set_intersection(left.acids[i].begin(), left.acids[i].end(),
                                 right.acids[i].begin(), right.acids[i].end(),
                                 inserter(parent.acids[i], parent.acids[i].begin()));
                
                // Set intersecion is empty, assign the union instead
                if (parent.acids[i].size() == 0) {
                    set_union(left.acids[i].begin(), left.acids[i].end(),
                              right.acids[i].begin(), right.acids[i].end(),
                              inserter(parent.acids[i], parent.acids[i].begin()));

                    cost++;
                }
            }

            // Push the parent back into the queue
            nodes.push(parent);
        }

        // Print the root node and the cost
        node root = nodes.front();
        for (int i = 0; i < root.acids.size(); i++) {
            cout << *(root.acids[i].begin());
        }

        cout << " " << cost << endl;
    }

    return 0;
}