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

//time: O(n), space: O(h)
//for queue based solution(BFS), space: O(w)
int getMax(Node *root)
{
    if (root == NULL)
        return INT_MIN;
    return max(root->data, max(getMax(root->left), getMax(root->right)));
}

int main()
{
    system("cls");

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(8);
    root->left->right = new Node(100);
    root->right->right = new Node(6);
    root->left->right->left = new Node(9);
    root->left->right->right = new Node(15);
    cout << getMax(root);
    return 0;
}