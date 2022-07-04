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

// logic: copy value of 2nd node into head node,point head to 3rd node,delete second node
Node *deletehead(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == head)
    {
        delete head;
        return NULL;
    }
    head->data = head->next->data;
    Node *temp = head->next;
    head->next = head->next->next;
    delete temp;
    return head;
}

Node *deleteKth(Node *head, int k)
{
    if (head == NULL)
        return head;
    if (k == 1)
        return deletehead(head);
    Node *current = head;
    for (int i = 0; i < k - 2; i++)
        current = current->next;
    Node *temp = current->next;
    current->next = current->next->next;
    delete temp;
    return head;
}

int main()
{
    system("cls");

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = head;
    int k;
    cout << "Enter k: ";
    cin >> k;
    head = deleteKth(head, k);
    traverseList(head);

    return 0;
}