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

void insertStart(ArrayList &list, int value)
{
    if (list.size < 20)
    {
        for (int i = list.size; i > 0; i--)
        {
            list.data[i] = list.data[i - 1];
        }

        list.data[0] = value;
        list.size++;
    }
}

void insertAfter(ArrayList &list, int specific, int value)
{
    if (list.size < 20)
    {
        for (int i = 0; i < list.size; i++)
        {
            if (list.data[i] == specific)
            {
                for (int j = list.size; j > i + 1; j--)
                {
                    list.data[j] = list.data[j - 1];
                }

                list.data[i + 1] = value;
                list.size++;
                return;
            }
        }
    }
}

void insertBefore(ArrayList &list, int specific, int value)
{
    if (list.size < 20)
    {
        for (int i = 0; i < list.size; i++)
        {
            if (list.data[i] == specific)
            {
                for (int j = list.size; j > i; j--)
                {
                    list.data[j] = list.data[j - 1];
                }

                list.data[i] = value;
                list.size++;
                return;
            }
        }
    }
}

void display(ArrayList &list)
{
    for (int i = 0; i < list.size; i++)
    {
        cout << list.data[i] << " ";
    }
    cout << endl;
}

void deleteEnd(ArrayList &list)
{
    if (list.size > 0)
    {
        list.size--;
    }
}

void deleteStart(ArrayList &list)
{
    if (list.size > 0)
    {
        for (int i = 0; i < list.size - 1; i++)
        {
            list.data[i] = list.data[i + 1];
        }

        list.size--;
    }
}

void deleteSpecific(ArrayList &list, int value)
{
    for (int i = 0; i < list.size; i++)
    {
        if (list.data[i] == value)
        {
            for (int j = i; j < list.size - 1; j++)
            {
                list.data[j] = list.data[j + 1];
            }

            list.size--;
            return;
        }
    }
}

int main()
{
    ArrayList list;

    insertEnd(list, 10);
    insertEnd(list, 20);
    insertEnd(list, 30);

    insertStart(list, 5);

    insertAfter(list, 20, 25);

    insertBefore(list, 30, 27);

    cout << "Array List: ";
    display(list);

    deleteEnd(list);

    cout << "After deleting from end: ";
    display(list);

    deleteStart(list);

    cout << "After deleting from start: ";
    display(list);

    deleteSpecific(list, 20);

    cout << "After deleting specific value: ";
    display(list);

    return 0;
}
