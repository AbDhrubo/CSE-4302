#include <iostream>
#include<algorithm>
using namespace std;
int m=INT_MIN;
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
    int N, q;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        for (char &c : word) {
            c = tolower(c); // Convert to lowercase
        }
        char a = word[0];
        string r = word.substr(1, word.size() - 2);
        sort(r.begin(), r.end());
        word = a + r + word[word.size() - 1];
                cout<<word<<endl;
        insert(word);
    }

    cin >> q;
    cin.ignore();

    for (int i = 0; i < q; i++) {
        int count = 1;
        string query;
        getline(cin, query);

        string word;
        for (char &c : query) {
            if (c == ' ') {
                char a = word[0];
                string r = word.substr(1, word.size() - 2);
                sort(r.begin(), r.end());
                word = a + r + word[word.size() - 1];
                count *= countWordsWithPrefix(word);
                word = "";
            } else {
                word += tolower(c);
            }
        }
        if (!word.empty()) {
            char a = word[0];
            string r = word.substr(1, word.size() - 2);
            sort(r.begin(), r.end());
            word = a + r + word[word.size() - 1];
            count *= countWordsWithPrefix(word);
        }
        cout << count << endl;
    }

    return 0;
}
