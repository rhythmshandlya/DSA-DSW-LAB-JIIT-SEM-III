/*
    Tower Of Hanoi has the following two rules:
      1. You can’t place a larger disk onto a smaller disk 
      2. Only one disk can be moved at a time
*/

#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

void towerOfHanoiRecursive(int n, char from, char to, char by)
{
    if (n == 0)
        return;
    //Move n-1
    towerOfHanoiRecursive(n - 1, from, by, to);
    cout << "Moving top ring of " << from << " to " << to << endl;
    towerOfHanoiRecursive(n - 1, by, to, from);
}

void moveDisk(stack<int> &s1, stack<int> &s2, char d1, char d2)
{
    if (s1.empty())
    {
        if (!s2.empty())
        {
            int disk = s2.top();
            s2.pop();
            s1.push(disk);
            cout << "Moving top ring of " << d2 << " to " << d1 << endl;
        }
        return;
    }
    if (s2.empty())
    {
        if (!s1.empty())
        {
            int disk = s1.top();
            s1.pop();
            s2.push(disk);
            cout << "Moving top ring of " << d1 << " to " << d2 << endl;
        }
        return;
    }
    if (s1.top() > s2.top())
    {
        int disk = s2.top();
        s2.pop();
        s1.push(disk);
        cout << "Moving top ring of " << d2 << " to " << d1 << endl;
        return;
    }
    if (s2.top() > s1.top())
    {
        int disk = s1.top();
        s1.pop();
        s2.push(disk);
        cout << "Moving top ring of " << d1 << " to " << d2 << endl;
        return;
    }
}

void towerOfHanoiIterative(int n)
{
    /*
        1. Calculate the total number of moves required i.e. "pow(2, n) - 1" here n is number of disks.
        2. If number of disks (i.e. n) is even then interchange destination pole and auxiliary pole.
        3. for i = 1 to total number of moves:
            if i%3 == 1: legal movement of top disk between source pole and destination pole
            if i%3 == 2: legal movement top disk between source pole and auxiliary pole
            if i%3 == 0: legal movement top disk between auxiliary pole and destination pole 
            s<->d
            s<->a
            a<->d
    */

    stack<int> s, d, a;
    int total_moves = pow(2, n) - 1;

    for (int i = n; i > 0; i--)
        s.push(i);

    for (int i = 1; i <= total_moves; i++)
    {

        if (i % 3 == 0)
        {
            moveDisk(a, d, 'A', 'D');
        }
        else if (i % 3 == 1)
        {
            moveDisk(s, d, 'S', 'D');
        }
        else
        {
            moveDisk(s, a, 'S', 'A');
        }
    }
}

int main()
{
    int n;
    cin >> n;
    cout << "Iterative\n";
    towerOfHanoiIterative(n);
    cout << "Recursive\n";
    towerOfHanoiRecursive(n, 'S', 'D', 'A');
    return 0;
}