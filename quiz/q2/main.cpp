#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int d = 0)
    {
        next = NULL;
        prev = NULL;
        data = d;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    void print();
    void push_back(int);
    void swapEnd();
};

void LinkedList::push_back(int data)
{
    if (!head)
    {
        head = new Node(data);
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(data);
    newNode->prev = temp;
    temp->next = newNode;
}

void LinkedList::print()
{
    if (!head)
    {
        cout << "List Empty";
        return;
    }
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void LinkedList ::swapEnd()
{
    if (!head)
    {
        cout << "List Empty!\n";
        return;
    }

    Node *forward = head;
    Node *backword = head;

    int count = 1;
    while (backword->next)
    {
        count++;
        backword = backword->next;
    }

    count /= 2;
    while (count--)
    {
        swap(forward->data, backword->data);
        forward = forward->next;
        backword = backword->prev;
        if (count == 0)
        {
            cout << "\nFinal list :";
        }
        print();
    }
}

int main()
{
    LinkedList *list = new LinkedList();
    list->push_back(1);
    list->push_back(2);
    list->push_back(3);
    list->push_back(4);
    list->push_back(5);
    list->push_back(6);
    list->push_back(7);
    list->push_back(8);
    list->push_back(9);
    list->push_back(10);

    cout << "\nInitial List: ";
    list->print();
    cout << endl;
    list->swapEnd();
    return 0;
}