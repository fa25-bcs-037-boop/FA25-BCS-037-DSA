#include <iostream>
using namespace std;

struct ArrayList
{
    int data[20];
    int size = 0;
};

void insertEnd(ArrayList &list, int value)
{
    if (list.size < 20)
    {
        list.data[list.size] = value;
        list.size++;
    }
}

int main()
{
    ArrayList list;

    insertEnd(list, 10);
    insertEnd(list, 20);
    insertEnd(list, 30);
    insertEnd(list, 40);
    insertEnd(list, 50);

    int value;
    int i = 0;
    bool found = false;

    cout << "Enter value to search: ";
    cin >> value;

    while (i < list.size)
    {
        if (list.data[i] == value)
        {
            found = true;
            break;
        }

        i++;
    }

    if (found)
    {
        cout << "Value found at index " << i;
    }
    else
    {
        cout << "Value not found";
    }

    return 0;
}
