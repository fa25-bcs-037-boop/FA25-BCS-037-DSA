#include <iostream>
using namespace std;

struct SNode
{
    int data;
    SNode* next;
};

struct DNode
{
    int data;
    DNode* next;
    DNode* prev;
};

void insertSingly(SNode*& head, int value)
{
    SNode* newNode = new SNode;

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    SNode* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

DNode* convertToDoubly(SNode* head)
{
    if (head == NULL)
        return NULL;

    DNode* dHead = NULL;
    DNode* dTail = NULL;

    SNode* temp = head;

    while (temp != NULL)
    {
        DNode* newNode = new DNode;

        newNode->data = temp->data;
        newNode->next = NULL;
        newNode->prev = dTail;

        if (dHead == NULL)
        {
            dHead = newNode;
        }
        else
        {
            dTail->next = newNode;
        }

        dTail = newNode;
        temp = temp->next;
    }

    return dHead;
}

void displayDoubly(DNode* head)
{
    DNode* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    SNode* head = NULL;

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        insertSingly(head, value);
    }

    DNode* doublyHead = convertToDoubly(head);

    cout << "Doubly Linked List: ";
    displayDoubly(doublyHead);

    return 0;
}
