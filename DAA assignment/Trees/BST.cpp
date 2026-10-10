#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* createTree()
{
    int value;
    cin >> value;

    if (value == -1)
        return nullptr;

    Node* root = new Node(value);

    cout << "Enter left child of " << value << " (-1 for none): ";
    root->left = createTree();

    cout << "Enter right child of " << value << " (-1 for none): ";
    root->right = createTree();

    return root;
}

void displayTree(Node* root, string prefix = "", bool isLeft = true)
{
    if (root == nullptr)
        return;

    cout << prefix;

    if (prefix != "")
        cout << (isLeft ? "├── " : "└── ");

    cout << root->data << endl;

    string newPrefix = prefix + (isLeft ? "│   " : "    ");

    displayTree(root->left, newPrefix, true);
    displayTree(root->right, newPrefix, false);
}

int main()
{
    cout << "Enter root value (-1 for empty): ";
    Node* root = createTree();

    cout << "\nBinary Tree:\n";
    displayTree(root, "", true);

    return 0;
}