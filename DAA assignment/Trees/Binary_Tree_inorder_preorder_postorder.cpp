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

void preorder(Node* root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root)
{
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node* createTree()
{
    int value;

    cout << "Enter node value (-1 for no node): ";
    cin >> value;

    if (value == -1)
        return nullptr;

    Node* root = new Node(value);

    cout << "Enter left child of " << value << ":\n";
    root->left = createTree();

    cout << "Enter right child of " << value << ":\n";
    root->right = createTree();

    return root;
}

void deleteTree(Node* root)
{
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main()
{
    cout << "Create the binary tree:\n";
    Node* root = createTree();

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    deleteTree(root);

    return 0;
}