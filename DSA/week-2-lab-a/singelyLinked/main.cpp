#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
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
    ~Node()
    {
        delete next;
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
    Node *getHead()
    {
        return head;
    }

    void push_back(int data);
    void push_front(int data);
    void push(int index, int data);
    void sort();
    void storeDigits(int num);
    Node *reverseRange(int x, int y);
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

void print(Node *head)
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

Node *LinkedList::reverseRange(int left, int right)
{
    Node *temp = head;
    right = right - left + 1;

    if (left == 1)
    {
        Node *prev = NULL, *next = NULL;
        while (right-- && temp)
        {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        head->next = next;
        head = prev;
    }
    else
    {
        while (--left > 1)
        {
            temp = temp->next;
        }

        Node *n1 = temp;
        temp = temp->next;
        Node *n2 = temp;

        Node *prev = NULL, *next = NULL;
        while (right-- && temp)
        {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        n1->next = prev;
        n2->next = next;
    }
    return head;
}

Node *merge(Node *h1, Node *h2)
{
    if (!h1)
        return h2;
    if (!h2)
        return h1;

    Node *result = NULL;
    if (h1->data <= h2->data)
    {
        result = h1;
        h1->next = merge(h1->next, h2);
    }
    else
    {
        result = h2;
        h2->next = merge(h1, h2->next);
    }
    return result;
}

Node *mergeSort(Node *head)
{
    if (head->next == NULL)
        return head;

    Node *fast = head->next, *slow = head;
    while (fast)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    Node *h2 = mergeSort(slow->next);
    slow->next = NULL;
    Node *h1 = mergeSort(head);
    Node *ans = merge(h1, h2);
    return ans;
}

void LinkedList::sort()
{
    head = mergeSort(head);
}

int main()
{
    srand(time(0));
    LinkedList *list = new LinkedList();
    for (int i = 0; i < 100; i++)
    {
        list->push_back(rand() % 1000);
    }

    list->print();
    list->sort();
    list->print();

    return 0;
}