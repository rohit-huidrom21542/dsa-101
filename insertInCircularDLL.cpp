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

Node *insertAtBegin(Node *head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }
    newNode->prev = head->prev;
    newNode->next = head;
    head->prev->next = newNode;
    head->prev = newNode;
    return newNode;
}

Node *insertAtEnd(Node *head, int d)
{
    Node *newNode = new Node(d);
    if (head == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }
    newNode->prev = head->prev;
    newNode->next = head;
    head->prev->next = newNode;
    head->prev = newNode;
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
    } while (current != head);
}

int main()
{
    system("cls");

    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    head->prev = temp2;
    temp1->next = temp2;
    temp1->prev = head; 
    temp2->prev = temp1;
    temp2->next = head;
    head = insertAtBegin(head, 100);
    head = insertAtEnd(head, 200);
    traverse(head);

    return 0;
}