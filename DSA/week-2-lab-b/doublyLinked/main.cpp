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
    void printRev();
    int coutNode();
    int maxNode();
    int minNode();

    void push_back(int data);
    void push_front(int data);
    void push(int index, int data);
    void storeDigits(int num);
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

void LinkedList::push_front(int data)
{
    if (!head)
    {
        head = new Node(data);
        return;
    }
    Node *newHead = new Node(data);
    newHead->next = head;
    head->prev = newHead;
    head = newHead;
}

void LinkedList::push(int index, int data)
{
    if (index < 0)
        cout << "Invalid Index To Push Function";

    if (index == 0)
    {
        push_front(data);
        return;
    }

    Node *temp = head;
    while (temp && index > 1)
    {
        temp = temp->next;
        --index;
    }

    cout << temp->data << " ";
    Node *newNode = new Node(data);
    newNode->next = temp->next;
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

void LinkedList::printRev()
{
    if (!head)
    {
        cout << "List Empty";
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    LinkedList *list = new LinkedList();
    list->push_back(10);
    list->push_back(11);
    list->push_back(12);
    list->push_back(13);
    list->push(5, 100);
    list->print();
    return 0;
}