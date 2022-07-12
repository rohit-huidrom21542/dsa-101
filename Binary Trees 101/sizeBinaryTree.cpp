#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

//time : O(n), space: O(h)
int sizeBinaryTree(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + sizeBinaryTree(root->left) + sizeBinaryTree(root->right);
}

int main()
{
    system("cls");

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(8);
    root->left->right = new Node(7);
    root->right->right = new Node(6);
    root->left->right->left = new Node(9);
    root->left->right->right = new Node(15);
    cout << sizeBinaryTree(root);
    return 0;
}