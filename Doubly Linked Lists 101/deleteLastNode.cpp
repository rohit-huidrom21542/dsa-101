// time : 0(n)

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int d)
    {
        data = d;
        next = prev = NULL;
    }
};

Node *deleteLastNode(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->prev->next = NULL;
    delete current;
    return head;
}

void traverse(Node *head)
{
    if (head == NULL)
        return;
    Node *current = head;
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != NULL);
}

int main()
{
    system("cls");

    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    temp1->next = temp2;
    temp1->prev = head;
    temp2->prev = temp1;
    head = deleteLastNode(head);
    traverse(head);

    return 0;
}