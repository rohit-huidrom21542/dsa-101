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

Node *reverse(Node *head)
{
    if (head == NULL or head->next == NULL)
        return head;
    Node *current = head, *prev = NULL;
    while (current != NULL)
    {
        //swapping prev and next references
        prev = current->prev;
        current->prev = current->next;
        current->next = prev;

        current = current->prev; //since next and prev were swapped
    }
    return prev->prev;
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
    head = reverse(head);
    traverse(head);

    return 0;
}