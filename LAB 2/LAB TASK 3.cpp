#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void insertEnd(Node*& head, int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

Node* mergeLists(Node* head1, Node* head2)
{
    Node* head3 = NULL;

    Node* temp = head1;

    while (temp != NULL)
    {
        insertEnd(head3, temp->data);
        temp = temp->next;
    }

    temp = head2;

    while (temp != NULL)
    {
        insertEnd(head3, temp->data);
        temp = temp->next;
    }

    return head3;
}

void display(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* head3 = NULL;

    insertEnd(head1, 10);
    insertEnd(head1, 20);
    insertEnd(head1, 30);

    insertEnd(head2, 40);
    insertEnd(head2, 50);
    insertEnd(head2, 60);

    head3 = mergeLists(head1, head2);

    cout << "First List: ";
    display(head1);

    cout << "\nSecond List: ";
    display(head2);

    cout << "\nMerged List: ";
    display(head3);

    return 0;
}
