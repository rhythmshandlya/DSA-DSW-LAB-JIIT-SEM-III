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
    Node(int data = 0)
    {
        this->data = data;
        next = NULL;
    }
};

class List
{
    Node *head;

public:
    List()
    {
        head = NULL;
    }
    void print();
    void insert(int data);
    void printReverse();
};

void List::print()
{
    Node *temp = head;
    while (temp->next)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data;
}

void List::insert(int data)
{
    if (!head)
    {
        Node *newNode = new Node(data);
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next)
        temp = temp->next;
    Node *newNode = new Node(data);
    temp->next = newNode;
}

void List::printReverse()
{
    Node *temp = head;
    Node *lastNode = NULL;
    while (temp->next)
        temp = temp->next;
    lastNode = temp;
    temp = head;

    while (lastNode != head)
    {
        while (temp->next != lastNode)
            temp = temp->next;
        cout << lastNode->data << "<-";
        lastNode = temp;
        temp = head;
    }
    cout << lastNode->data;
    return;
}

int main()
{
    List *l = new List;
    l->insert(10);
    l->insert(20);
    l->insert(30);
    l->insert(40);
    l->insert(50);
    l->print();
    cout << endl;
    l->printReverse();

    return 0;
}