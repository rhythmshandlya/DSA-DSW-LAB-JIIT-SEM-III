// { Driver Code Starts
// driver

#include <iostream>
using namespace std;

/* Linked list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

Node *reverseList(struct Node *temp)
{
    Node *prev = NULL, *next = NULL;
    cout << "Reversing List\n";
    while (temp->next)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    temp->next = prev;
    return temp;
}

Node *addTwoLists(struct Node *first, struct Node *second)
{
    first = reverseList(first);
    second = reverseList(second);
    Node *ans = NULL;
    Node *final = NULL;

    int carry = 0;
    while (first != NULL || second != NULL)
    {
        int sum = carry;
        if (first)
        {
            sum += first->data;
            first = first->next;
        }

        if (second)
        {
            sum += second->data;
            second = second->next;
        }

        if (!ans)
        {
            ans = new Node(sum % 10);
            final = ans;
        }
        else
        {
            Node *digit = new Node(sum % 10);
            ans->next = digit;
            ans = digit;
        }
        carry = sum / 10;
    }
    if (carry)
    {
        Node *digit = new Node(carry);
        ans->next = digit;
        ans = digit;
    }
    final = reverseList(final);
    return final;
}

// { Driver Code Starts.

int main()
{
    int n, m;

    cin >> n;
    Node *first = buildList(n);

    cin >> m;
    Node *second = buildList(m);

    Node *res = addTwoLists(first, second);

    printList(res);
    return 0;
}
// } Driver Code Ends
