/*
Q. No. 1:- Write a program to sort the element in the stack using recursion.

Example:
Stack before sorting :- 5 | -2 | 9 | -7 | 3 , where 3 is the top element
Stack after sorting :- 7 | -2 | 3 | 5 | 9, where 9 is the top element
Idea: recursively remove values from the stack until the stack becomes empty and then
insert those values (from the call stack) back into the stack in a sorted position.
*/
/* C++ program to implement basic stack
   operations
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000

class Stack
{
    int top;

public:
    int a[MAX];

    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int getTop() { return top; }
    int peek();
    bool isEmpty();
    void erase();
    void sortStack();
};

bool Stack::push(int x)
{
    if (top >= (MAX - 1))
    {
        cout << "Stack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        return true;
    }
}

int Stack::pop()
{
    if (top < 0)
    {
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}

void Stack::erase()
{
    top = -1;
}

int Stack::peek()
{
    if (top < 0)
    {
        return 0;
    }
    else
    {
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

void Stack::sortStack()
{
    int arr[MAX];
    int top_cpy = getTop();
    for (int i = 0; i < top_cpy; i++)
    {
        arr[i] = peek();
        pop();
    }
    sort(arr, arr + top_cpy);

    erase();
    for (int i = 0; i < top_cpy; i++)
    {
        push(arr[i]);
    }
}

int main()
{
    class Stack s;
    for (int i = 0; i < 10; i++)
    {
        int n;
        cin >> n;
        s.push(n);
    }
    s.sortStack();
    while (!s.isEmpty())
    {
        cout << s.peek() << " ";
        s.pop();
    }
    return 0;
}