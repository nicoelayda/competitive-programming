#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

int diff(string w1, string w2) {
    if (w1.length() != w2.length())
        return -1;

    int difference = 0;

    for (int i = 0; i < w1.length(); i++) {
        if (w1[i] != w2[i])
            difference++;
    }

    return difference;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T-- != 0) {
        string word;
        map<string, int> words;
        vector<string> word_list;
        int num_words = 0;

        while (getline(cin, word) && word != "*") {
            words[word] = num_words++;
            word_list.push_back(word);
        }

        vector<int> adj_list[num_words];
        
        for (int i = 0; i < num_words; i++) {
            for (int j = i + 1; j < num_words; j++) {
                if (diff(word_list[i], word_list[j]) == 1) {
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
            }
        }
        
        string line;
        while (getline(cin, line) && line.length() != 0) {
            istringstream iss(line);
            string start_word, end_word;
            iss >> start_word >> end_word;

            int source = words[start_word];
            int dest = words[end_word];

            queue<int> fringe;
            vector<int> dist(num_words, numeric_limits<int>::max());
            vector<bool> visited(num_words, false);

            fringe.push(source);
            dist[source] = 0;
            visited[source] = true;

            while (!fringe.empty()) {
                int u = fringe.front(); fringe.pop();

                for (int i = 0; i < adj_list[u].size(); i++) {
                    int v = adj_list[u][i];

                    if (!visited[v]) {
                        dist[v] = dist[u] + 1;
                        visited[v] = true;
                        fringe.push(v);
                    }
                }
            }

            cout << start_word << " " << end_word << " " << dist[dest] << endl;
        }

        if (T != 0)
            cout << endl;
    }

    return 0;
}