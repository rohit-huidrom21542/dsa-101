#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k)
    {
        key = k;
        left = NULL;
        right = NULL;
    }
};

// time: O(n), space: O(h+1) ie O(h),  h=heigth of tree
void inorderTraversal(Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        cout << root->key << " ";
        inorderTraversal(root->right);          
    }
}
// time: O(n), space: O(h+1) ie O(h),  h=heigth of tree
void preorderTraversal(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
// time: O(n), space: O(h+1) ie O(h),  h=heigth of tree
void postorderTraversal(Node *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->key << " ";
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

    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << "\nPreorder traversal: ";
    preorderTraversal(root);
    cout << "\nPostorder traversal: ";
    postorderTraversal(root);
    return 0;
}

// we represent an empty tree as NULL ie root==NULL