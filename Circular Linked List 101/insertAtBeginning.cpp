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

// logic: insert new Node after the head node, and swap the data in head node and the new node
void insertAtBegin(Node *head, int n)
{
    Node *temp = new Node(n);
    if (head == NULL)
        temp->next = temp;
    else
    {
        temp->next = head->next;
        head->next = temp;
        int t = head->data;
        head->data = temp->data;
        temp->data = t;
    }
}

int main()
{
    system("cls");

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = head;
    insertAtBegin(head, 100);
    traverseList(head);

    return 0;
}