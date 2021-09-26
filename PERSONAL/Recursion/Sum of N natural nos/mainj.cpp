#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int sumN(int n)
{
    if (n == 1)
        return 1;
    return n + sumN(n - 1);
}

bool checkPalindrom(string &str, int n1, int n2)
{
    if (n1 >= n2)
        return true;
    return str[n1] == str[n2] && checkPalindrom(str, n1 + 1, n2 - 1);
}

int cutRope(int n, int a, int b, int c)
{
    if (n == 0)
        return 1;

    int m1, m2, m3;
    m1 = cutRope(n - a, a, b, c);
    m2 = cutRope(n - b, a, b, c);
    m3 = cutRope(n - c, a, b, c);

    int res = max(max(m1, m2), m3);

    return max(max(m1, m2), m3) + 1;
}

int countZeroes(int n)
{
    if (n == 0)
        return 1;
    if (n / 10 == 0)
        return 0;
    else if (n % 10 == 0)
        return 1 + countZeroes(n / 10);
    else
        return countZeroes(n / 10);
}

//Iterative Using An Array
int josephI(int n, int k)
{
    int *arr = new int[n]();
    int i = 0, count = 1, n_cpy = n;

    while (1)
    {
        if (count == k && arr[i % n] != 1)
        {
            count = 1;
            arr[i % n] = 1;
            n_cpy--;
            if (n_cpy == 0)
            {
                return i % n;
            }
        }
        if (arr[i % n] == 0)
        {
            ++count;
        }
        i++;
    }
    return -1;
}

//Joseph Using recursion
int josephR(int n, int k)
{
    if (n == 1)
        return 0;
    return (josephR(n - 1, k) + k) % n;
}

int main()
{
    cout << josephR(35, 4) << endl;
    return 0;
}