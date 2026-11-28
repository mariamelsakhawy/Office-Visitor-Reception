#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    string name;
    struct Node* left, * right;

    Node(int data, string name) {
        this->data = data;
        this->name = name;
        left = right = NULL;
    }
};


Node* insert(Node* root, int id, string name) {

    if (root == nullptr)
        return new Node(id, name);

    if (id < root->data)
        root->left = insert(root->left, id, name);

    else if (id > root->data)
        root->right = insert(root->right, id, name);

    else
        cout << "This ID already exists!" << endl;

    return root;
}

Node* search(Node* root, int id) {
    if (root == nullptr) return nullptr;

    if (root->data == id) return root;

    if (id > root->data)
        return search(root->right, id);

    else
        return search(root->left, id);
}

void inorder(Node* node) {
    if (node == NULL)
        return;

    inorder(node->left);
    cout << node->data << " (" << node->name << ")  ";
    inorder(node->right);
}

int main() {
    Node* root = nullptr;
    int choice;

    do {
        cout << "1. Add visitor" << endl;
        cout << "2. Search visitor by ID" << endl;
        cout << "3. Show all visitors (Inorder)" << endl;
        cout << "0. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name, lastName;

            cout << "Enter visitor ID: ";
            cin >> id;
            cout << "Enter visitor first name: ";
            cin >> name;
            cout << "Enter visitor last name: ";
            cin >> lastName;
            name = name + " " + lastName;
            root = insert(root, id, name);
        }

        else if (choice == 2) {
            int id;
            cout << "Enter visitor ID to search: ";
            cin >> id;

            Node* result = search(root, id);
            if (result != nullptr)
                cout << "Found: " << result->name << endl;

            else
                cout << "Not found" << endl;
        }

        else if (choice == 3) {
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
        }
    } while (choice != 0);

    return 0;
}