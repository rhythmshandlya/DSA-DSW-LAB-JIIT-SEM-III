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
    Node(int d = 0)
    {
        next = NULL;
        data = d;
    }
};

class LinkedList
{

public:
    Node *head;
    Node *tail;
    LinkedList()
    {
        head = NULL;
    }
    LinkedList(Node *head)
    {
        this->head = head;
    }
    void push_back(int);
    void print();
    void concat(LinkedList *);
    void split(Node **, Node **);
};
void LinkedList::push_back(int data)
{
    if (!head)
    {
        head = new Node(data);
        head->next = head;
        tail = head;
        return;
    }
    Node *newNode = new Node(data);
    tail->next = newNode;
    newNode->next = head;
    tail = newNode;
}

void LinkedList::print()
{
    if (!head)
    {
        cout << "LinkedList Empty!";
        return;
    }
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

void LinkedList::concat(LinkedList *ls)
{
    tail->next = ls->head;
    ls->tail = head;
    tail = ls->tail;
}

void LinkedList::split(Node **h1, Node **h2)
{
    Node *slow = head;
    Node *fast = head;
    if (!head)
        return;
    while (fast->next->next != head && fast->next != head)
    {
        fast = fast->next->next;
        slow = slow->next;
    };
    if (fast->next->next == head)
        fast = fast->next;

    *h1 = head;
    *h2 = slow->next;

    fast->next = slow->next;
    slow->next = head;
}

int main()
{
    LinkedList *list = new LinkedList();
    list->push_back(10);
    list->push_back(20);
    list->push_back(30);
    list->push_back(40);
    list->push_back(50);
    list->push_back(60);
    list->push_back(100);
    list->push_back(110);
    list->push_back(120);

    list->print();
    cout << endl;

    Node *h1, *h2;
    list->split(&h1, &h2);

    LinkedList *list1 = new LinkedList(h1);
    LinkedList *list2 = new LinkedList(h2);

    cout << "List One: ";
    list1->print();
    cout << endl;

    cout << "List Two: ";
    list2->print();
    cout << endl;

    system("pause");
}