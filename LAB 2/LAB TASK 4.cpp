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

void findOccurrences(Node* head, int value)
{
    Node* temp = head;
    int position = 0;
    int count = 0;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            cout << "Value found at position " << position << endl;
            count++;
        }

        temp = temp->next;
        position++;
    }

    if (count == 0)
    {
        cout << "Value not found";
    }
    else
    {
        cout << "Total occurrences: " << count;
    }
}

int main()
{
    Node* head = NULL;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 10);
    insertEnd(head, 30);
    insertEnd(head, 10);
    insertEnd(head, 40);

    int value;

    cout << "Enter value to search: ";
    cin >> value;

    findOccurrences(head, value);

    return 0;
}
