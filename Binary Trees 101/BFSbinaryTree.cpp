// time : 0(n), sapce: 0(w) , w = width of binary tree

// this traversal is also known as Level Order Traversal

#include <iostream>
#include <queue>
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

void bfs(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        Node *current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }
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

    bfs(root);

    return 0;
}