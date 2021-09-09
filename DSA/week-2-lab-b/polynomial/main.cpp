#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Node
{
public:
    int val;
    int exp;
    Node *next;
    Node *prev;
    Node(int val, int exp)
    {
        this->val = val;
        this->exp = exp;
        next = NULL;
        prev = NULL;
    }
};

class Polynomial
{
    Node *head;

public:
    Polynomial()
    {
        head = NULL;
    }
    void insert(int, int);
    void print();
    friend Polynomial *multiply(Polynomial *, Polynomial *);
};

void Polynomial::insert(int val, int exp)
{
    Node *temp = head;
    if (!temp)
    {
        Node *newNode = new Node(val, exp);
        head = newNode;
        return;
    }
    while (temp)
    {
        if (temp->exp == exp)
        {
            temp->val += val;
            return;
        }
        if (temp->exp > exp)
        {
            Node *newNode = new Node(val, exp);
            if (temp == head)
            {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
                return;
            }
            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            temp->prev = newNode;
            return;
        }
        if (!temp->next)
        {
            Node *newNode = new Node(val, exp);
            temp->next = newNode;
            newNode->prev = temp;
            return;
        }

        temp = temp->next;
    }
}

void Polynomial::print()
{
    Node *temp = head;
    if (!temp)
    {
        cout << "1 ";
        return;
    }
    while (temp)
    {
        if (!temp->next)
        {
            cout << temp->val << "X^" << temp->exp;
            return;
        }
        cout << temp->val << "X^" << temp->exp << " + ";
        temp = temp->next;
    }
}

Polynomial *multiply(Polynomial *x, Polynomial *y)
{
    Polynomial *newList = new Polynomial();

    Node *tempX = x->head;
    while (tempX)
    {
        Node *tempY = y->head;
        while (tempY)
        {
            newList->insert(tempX->val * tempY->val, tempX->exp + tempY->exp);
            tempY = tempY->next;
        }
        tempX = tempX->next;
    }
    return newList;
}

int main()
{
    Polynomial *a = new Polynomial();
    Polynomial *b = new Polynomial();

    // insert(constant,exponent);
    cout << "(";
    a->insert(1, 2);
    a->insert(2, 3);
    a->print();
    cout << ") X (";

    // b = 3X^3 + 5X^4 + 10X^1
    b->insert(3, 3);
    b->insert(5, 4);
    b->insert(10, 1);
    b->print();
    cout << ") = ";

    Polynomial *c = multiply(a, b);
    c->print();
    return 0;
}