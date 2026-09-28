#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

void insert(Node*& head, int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void swapNodes(Node*& head, int value1, int value2)
{
    Node* first = NULL;
    Node* second = NULL;
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->data == value1)
            first = temp;

        if (temp->data == value2)
            second = temp;

        temp = temp->next;
    }

    if (first == NULL || second == NULL)
    {
        cout << "Both values were not found.";
        return;
    }

    if (first == second)
    {
        cout << "Both values are in the same node.";
        return;
    }

    Node* firstPrev = first->prev;
    Node* firstNext = first->next;

    Node* secondPrev = second->prev;
    Node* secondNext = second->next;

    if (firstNext == second)
    {
        first->next = secondNext;
        first->prev = second;
        second->next = first;
        second->prev = firstPrev;

        if (secondNext != NULL)
            secondNext->prev = first;

        if (firstPrev != NULL)
            firstPrev->next = second;
        else
            head = second;
    }
    else if (secondNext == first)
    {
        second->next = firstNext;
        second->prev = first;
        first->next = second;
        first->prev = secondPrev;

        if (firstNext != NULL)
            firstNext->prev = second;

        if (secondPrev != NULL)
            secondPrev->next = first;
        else
            head = first;
    }
    else
    {
        if (firstPrev != NULL)
            firstPrev->next = second;
        else
            head = second;

        if (firstNext != NULL)
            firstNext->prev = second;

        if (secondPrev != NULL)
            secondPrev->next = first;
        else
            head = first;

        if (secondNext != NULL)
            secondNext->prev = first;

        first->prev = secondPrev;
        first->next = secondNext;

        second->prev = firstPrev;
        second->next = firstNext;
    }
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
    Node* head = NULL;
    int n, value;
    int value1, value2;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        insert(head, value);
    }

    cout << "Original List: ";
    display(head);

    cout << "\nEnter first value: ";
    cin >> value1;

    cout << "Enter second value: ";
    cin >> value2;

    swapNodes(head, value1, value2);

    cout << "\nAfter Swapping Nodes: ";
    display(head);

    return 0;
}
