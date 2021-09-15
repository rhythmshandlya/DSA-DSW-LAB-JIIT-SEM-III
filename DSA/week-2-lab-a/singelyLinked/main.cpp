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
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    void print();
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
    head = newHead;
}
void LinkedList::push(int index, int data)
{
    if (index < 0)
        cout << "Invalid Index To Push Function";

    if (!head && !index)
        push_front(data);

    Node *temp = head;
    while (index && temp)
    {
        temp = temp->next;
        index--;
    }
    if (temp)
    {
        Node *newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    else
        cout << "Invalid Index" << endl;
    return;
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
int LinkedList::coutNode()
{
    int count = 0;
    if (!head)
        return 0;

    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int LinkedList::maxNode()
{
    int mx = INT_MIN;
    if (!head)
    {
        return 0;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        mx = max(mx, temp->data);
        temp = temp->next;
    }
    return mx;
}

int LinkedList::minNode()
{
    int mn = INT_MAX;
    if (!head)
    {
        return mn;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        mn = min(mn, temp->data);
        temp = temp->next;
    }
    return mn;
}
void LinkedList::storeDigits(int num)
{
    int count = 0;
    int temp = num;
    while (temp > 0)
    {
        count++;
        temp /= 10;
    }
    int exp = pow(10, count - 1);
    while (exp > 0)
    {
        push_back((num / exp) % 10);
        exp /= 10;
    }
}

int main()
{
    LinkedList *list = new LinkedList();
    list->push_back(10);
    list->push_front(0);
    list->push_back(30);
    list->push(4, 5);
    list->print();

    int num;
    cin >> num;
    list->storeDigits(num);
    list->print();

    return 0;
}