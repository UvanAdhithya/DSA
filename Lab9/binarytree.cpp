// Menu of binary tree ADT operations
#include <iostream>
using namespace std;


// Class for Tree ADT
class Tree {
private:
    struct Node {
        char data;
        Node* left;
        Node* right;
    };
    Node* root;

    // Helper function to insert recursively
    Node* insert(Node* node, char value) {
        if (node == NULL) {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->left = newNode->right = NULL;
            return newNode;
        }
        char choice;
        cout << "Insert to left or right of " << node->data << "? (l/r): ";
        cin >> choice;

        if (choice == 'l' || choice == 'L') {
            node->left = insert(node->left, value);
        } else if (choice == 'r' || choice == 'R') {
            node->right = insert(node->right, value);
        } else {
            cout << "Invalid choice! Try again.\n";
        }
        return node;
    }

    // Helper function for preorder traversal
    void preorder(Node* node) {
        if (node == NULL) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Helper function for inorder traversal
    void inorder(Node* node) {
        if (node == NULL) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Helper function for postorder traversal
    void postorder(Node* node) {
        if (node == NULL) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    // Helper function to search for a character
    bool search(Node* node, char value) {
        if (node == NULL) return false;
        if (node->data == value) return true;
        return search(node->left, value) || search(node->right, value);
    }

public:
    Tree() {
        root = NULL;
    }
    void insert(char);
    void inorder();
    void postorder();
    void preorder();
    void search(char);
};

void displayMenu() {
    cout << "\nTree ADT Menu:\n";
    cout << "1. Insert\n";
    cout << "2. Preorder\n";
    cout << "3. Inorder\n";
    cout << "4. Postorder\n";
    cout << "5. Search\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Tree t;
    int choice;
    char value;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter character to insert: ";
                cin >> value;
                t.insert(value);
                break;
            case 2:
                t.preorder();
                break;
            case 3:
                t.inorder();
                break;
            case 4:
                t.postorder();
                break;
            case 5:
                cout << "Enter character to search: ";
                cin >> value;
                t.search(value);
                break;
            case 6:
                cout << "Exiting... Bye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

void Tree::insert(char value) {
    if (root == NULL) {
        root = new Node();
        root->data = value;
        root->left = root->right = NULL;
        cout << "Root inserted successfully.\n";
    } else {
        root = insert(root, value);
    }
}

// Preorder traversal
void Tree::preorder() {
    if (root == NULL) {
        cout << "Tree is empty.\n";
        return;
    }
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;
}

// Inorder traversal
void Tree::inorder() {
    if (root == NULL) {
        cout << "Tree is empty.\n";
        return;
    }
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;
}

// Postorder traversal
void Tree::postorder() {
    if (root == NULL) {
        cout << "Tree is empty.\n";
        return;
    }
    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;
}

// Search for a character in the tree
void Tree::search(char value) {
    if (search(root, value)) {
        cout << "Character '" << value << "' found in the tree.\n";
    } else {
        cout << "Character '" << value << "' not found.\n";
    }
}