#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

string decrypt(vector<int> ciphertext, string key) {
    stringstream plaintext;
    for (int i = 0; i < ciphertext.size(); i++) {
        plaintext << ((char) (ciphertext[i] ^ key[i%key.length()]));
    }

    return plaintext.str();
}

int main() {
    int n;
    char ch;
    vector<int> encrypted_text;
    while (cin >> n) {
        cin >> ch;
        encrypted_text.push_back(n);
    }

    for (int i = 'a'; i <= 'z'; i++) {
        for (int j = 'a'; j <= 'z'; j++) {
            for (int k = 'a'; k <= 'z'; k++) {
                stringstream key;
                key << ((char)i) << ((char)j) << ((char)k);
                cout << "Key: " << key.str() << " " << (i+j+k) <<endl;
                cout << decrypt(encrypted_text, key.str()) << endl;;
            }
        }
    }
}