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

    Node* left_rotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left) y->left->parent = x;
        y->parent = x->parent;
        if (!x->parent) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;
        y->left = x;
        x->parent = y;
        Update_height(x);
        Update_height(y);
        return y;
    }

    Node* right_rotate(Node* y) {
        Node* x = y->left;
        y->left = x->right;
        if (x->right) x->right->parent = y;
        x->parent = y->parent;
        if (!y->parent) root = x;
        else if (y == y->parent->left) y->parent->left = x;
        else y->parent->right = x;
        x->right = y;
        y->parent = x;
        Update_height(y);
        Update_height(x);
        return x;
    }

    void check_balance(Node* node) {
        int balance = balance_factor(node);

        if (balance > 1) {
            // Left heavy
            if (balance_factor(node->left) > 0) {
                // LL case
                cout << "Imbalance at node: " << node->data << endl;
                cout << "LL case" << endl;
                cout << "right_rotate(" <<node->data<<")"<< endl;
                right_rotate(node);
                //in_order_traversal(node);
            } else {
                // LR case
                cout << "Imbalance at node: " << node->data << endl;
                cout << "LR Case" << endl;
                cout << "left_rotate(" <<node->left->data<<")"<< endl;
                left_rotate(node->left);
                cout << "right_rotate(" <<node->data<<")"<< endl;
                right_rotate(node);
                //in_order_traversal(node);
            }
        } else if (balance < -1) {
            // Right heavy
            if (balance_factor(node->right) < 0) {
                // RR case
                cout << "Imbalance at node: " << node->data << endl;
                cout << "RR case" << endl;
                cout << "left_rotate(" <<node->data<<")"<< endl;
                left_rotate(node);
            } else {
                // RL case
                cout << "Imbalance at node: " << node->data << endl;
                cout << "RL Case" << endl;
                cout << "right_rotate(" <<node->right->data<<")"<< endl;
                right_rotate(node->right);
                cout << "left_rotate(" <<node->data<<")"<< endl;
                left_rotate(node);
            }
        }

        Update_height(root);
        print_avl();
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
        //check_balance(newNode);
        return newNode;
    }
    int f=0;
    void in_order_traversal(Node* node) {
        if (node == nullptr) return;
        in_order_traversal(node->left);
        cout << node->data << "(" << balance_factor(node) << ") ";
        if(balance_factor(node)>1 || balance_factor(node)<-1)
        {
            f=1;
        }
        in_order_traversal(node->right);
    }
    void check_imbalance(Node* node) {
        if (node == nullptr) return;
        check_imbalance(node->left);
        if(balance_factor(node)>1 || balance_factor(node)<-1)
        {
            check_balance(node);
        }
        check_imbalance(node->right);
    }

    void print_avl() {
        in_order_traversal(root);
        cout << endl;
    }
    void print_imbalance() {
        check_imbalance(root);
        cout << endl;
    }

    int getroot()
    {return root->data;};
};

int main() {
    BST tree;

    int key;
    while (true) {
        cin >> key;
        if (key == -1) break;
        Node* newNode = tree.insertion(key);
        tree.print_avl();
        if(tree.f==0)
        {
            cout<<"Balanced"<<endl;
        }
        else
        {
        tree.print_imbalance();
        }
        cout << "Root=" << tree.getroot() << endl;
        cout<<endl;
        tree.f=0;
    }

    return 0;
}
