#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int d)
    {
        data = d;
        right = left = NULL;
    }
};

// time: O(n), space: O(h)
void printAtKDistance(Node *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
    {
        cout << root->data << " ";
    }
    else
    {
        printAtKDistance(root->left, k - 1);
        printAtKDistance(root->right, k - 1);
    }
}

int main()
{
    system("cls");

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    printAtKDistance(root, 2);

    return 0;
}