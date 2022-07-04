//time : O(1)

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

void traverseList(Node *head)
{
    if (head == NULL)
        return;
    Node *current = head;
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
}

// logic: insert new node after head node, swap data in head node and new node, make the new node-> head of list
Node *insertAtEnd(Node *head, int data)
{
    Node *t = new Node(data);
    if (head == nullptr)
    {
        t->next = t;
        return t;
    }
    else
    {
        t->next = head->next;
        head->next = t;
        int temp = t->data;
        t->data = head->data;
        head->data = temp;
        return t;
    }
}

int main()
{
    system("cls");

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = head;
    head = insertAtEnd(head, 100);
    traverseList(head);

    return 0;
}