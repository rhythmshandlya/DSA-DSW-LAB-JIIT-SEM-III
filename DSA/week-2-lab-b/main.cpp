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

Node *push(Node *head, int data)
{
    if (!head)
    {
        head = new Node(data);
        return head;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(data);
    temp->next = newNode;
    return head;
}

void printList(Node *head)
{
    if (!head)
    {
        cout << "List Empty";
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}
int coutNode(Node *head)
{
    int count = 0;
    if (!head)
    {
        return 0;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
int maxNode(Node *head)
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

int main()
{
    Node *head = NULL;
    for (int i = 0; i < 5; i++)
    {
        int num;
        cin >> num;
        head = push(head, num);
    }
    printList(head);
    cout << "Total Nodes: " << coutNode(head) << "\n";
    cout << "Max : " << maxNode(head);
    return 0;
}