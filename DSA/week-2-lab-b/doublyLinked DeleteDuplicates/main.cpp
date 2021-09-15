#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_set>
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
    void deleteDuplicates();
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

void LinkedList::deleteDuplicates()
{
    unordered_set<int> st;
    Node *temp = head;
    while (temp)
    {
        //cout << temp->data << " ";
        if (st.find(temp->data) == st.end())
            st.insert(temp->data);
        else
        {
            temp->prev->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
        }
        temp = temp->next;
    }
}

int main()
{
    LinkedList *list = new LinkedList();
    //1 2 2 3 4 2 2 5 2 1
    for (int i = 0; i < 10; i++)
    {
        int num;
        cin >> num;
        list->push_back(num);
    }
    list->deleteDuplicates();
    list->print();
    return 0;
}