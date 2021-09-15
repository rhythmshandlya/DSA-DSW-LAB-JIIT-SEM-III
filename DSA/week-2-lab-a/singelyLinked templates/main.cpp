#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

template <typename TN>
class Node
{
public:
    TN data;
    Node *next;
    Node *prev;
    Node(int d = 0)
    {
        next = NULL;
        prev = NULL;
        data = d;
    }
};

template <typename TL>
class LinkedList
{
    Node<TL> *head;

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

    void push_back(int);
    void pop_back();
    void push_front(int);
    void push(int, int);
    void storeDigits(int);

    void deleteElement(int);
    void swapExtream();
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

void LinkedList::pop_back()
{
    if (!head)
    {
        cout << "List Empty!\n";
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete temp;
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
void LinkedList::deleteElement(int index)
{
    if (index < 0)
    {
        cout << "Invalid Index To DeleteElement Function\n";
        return;
    }
    if (index == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    Node *temp = head;
    while (index && temp)
    {
        temp = temp->next;
        index--;
    }
    if (temp)
    {
        temp->prev->next = temp->next;
        delete temp;
    }
    else
        cout << "Invalid Index To DeleteElement Function/n";
}
void LinkedList::push(int index, int data)
{
    if (index < 0)
    {
        cout << "Invalid Index To Push Function/n";
        return;
    }

    if (index == 0)
    {
        push_front(data);
        return;
    }

    Node *temp = head;

    index++;
    while (temp && index)
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

void LinkedList ::swapExtream()
{
    if (!head)
    {
        cout << "List Empty!\n";
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    swap(temp->data, head->data);
}
int main()
{
    /*   LinkedList *list = new LinkedList();
    list->push_back(10);
    list->push_back(11);
    list->push_back(12);
    list->push_back(14);
    list->push_back(15);
    list->print();
    list->swapExtream();
    list->print(); */
    return 0;
}