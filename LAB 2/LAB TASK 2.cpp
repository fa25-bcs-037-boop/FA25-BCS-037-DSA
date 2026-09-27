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

void displayReverse(Node* head)
{
    if (head == NULL)
    {
        return;
    }

    displayReverse(head->next);

    cout << head->data << " ";
}

int main()
{
    Node* head = NULL;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);
    insertEnd(head, 50);

    cout << "Reverse List: ";
    displayReverse(head);

    return 0;
}
