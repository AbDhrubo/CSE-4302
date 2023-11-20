#include <iostream>
using namespace std;

struct Node {
    Node* next[26];
    int words_with_prefix;
    Node() {
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
        words_with_prefix = 0;
    }
};

Node* root = new Node();

void insert(string &str) {
    Node* curr = root;
    for (char c : str) {
        int idx = c - 'a';
        if (curr->next[idx] == nullptr) {
            curr->next[idx] = new Node();
        }
        curr = curr->next[idx];
        curr->words_with_prefix++;
        //cout<<curr->words_with_prefix;
    }
}

int countWordsWithPrefix(string &prefix) {
    Node* curr = root;
    for (char c : prefix) {
        int idx = c - 'a';
        if (curr->next[idx] == nullptr) {
            return 0;
        }
        curr = curr->next[idx];
    }
    return curr->words_with_prefix;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        for (char &c : word) {
            c = tolower(c); // Convert to lowercase
        }
        insert(word);
    }

    for (int i = 0; i < Q; i++) {
        string query;
        cin >> query;
        for (char &c : query) {
            c = tolower(c); // Convert to lowercase
        }
        int count = countWordsWithPrefix(query);
        cout << count << endl;
    }

    return 0;
}
