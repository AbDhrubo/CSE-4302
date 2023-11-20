#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
    int height;
};

class BST {
private:
    Node* root;

public:
    BST() {
        root = nullptr;
    }

    int height(Node* node) {
        if (node == nullptr) return -1;
        return node->height;
    }

    int balance_factor(Node* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    void Update_height(Node* node) {
        if (node) {
            node->height = 1 + max(height(node->left), height(node->right));
            Update_height(node->parent);
        }
    }

    Node* insertion(int key) {
        Node* newNode = new Node;
        newNode->data = key;
        newNode->left = newNode->right = newNode->parent = nullptr;
        newNode->height = 0;

        if (root == nullptr) {
            root = newNode;
        } else {
            Node* current = root;
            Node* parent = nullptr;
            while (current != nullptr) {
                parent = current;
                if (key < current->data) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }
            newNode->parent = parent;
            if (key < parent->data) {
                parent->left = newNode;
            } else {
                parent->right = newNode;
            }
        }

        Update_height(newNode);
        return newNode;
    }

    void in_order_traversal(Node* node) {
        if (node == nullptr) return;
        in_order_traversal(node->left);
        cout << node->data << "(" << balance_factor(node) << ") ";
        in_order_traversal(node->right);
    }

    void print_in_order() {
        in_order_traversal(root);
        cout << endl;
    }
};

int main() {
    BST tree;

    int key;
    while (true) {
        cin >> key;
        if (key == -1) break;
        Node* newNode = tree.insertion(key);
        tree.print_in_order();
    }

    return 0;
}
