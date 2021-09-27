#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
/*
Start with any positive integer (an initial seed) and obtain a sequence of numbers by following these rules.
1. If the current number is even, divide it by two; else if it is odd, multiply it by three and add one. 
2. Repeat.
THE NUMBER WILL END UP LIKE 4 2 1
*/

void getHailstoneSeq(int n)
{
    cout << n << " ";
    if (n == 1)
        return;
    else if (n % 2 == 0)
        getHailstoneSeq(n / 2);
    else
        getHailstoneSeq((n * 3) + 1);
}

using namespace std;

int main()
{
    int n;
    cin >> n;
    getHailstoneSeq(n);
    return 0;
}