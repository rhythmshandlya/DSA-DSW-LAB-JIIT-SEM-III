/*
    Q. No. 2:- Consider a string as an input, print all the possible palindromic partitions.
    Example:
        Input: nitin
        Output: n iti n
        Input: good
        Output: g oo d
*/

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrom(string str)
{
    string cpy(str);
    reverse(str.begin(), str.end());
    return str == cpy;
}

void allSubsequences(string &str, int index = 0, string print = "")
{
    if (index == str.length())
    {
        cout << print << " ";
        return;
    }
    allSubsequences(str, index + 1, print);
    allSubsequences(str, index + 1, print + str[index]);
}

void allSubstring()
{
}

int main()
{
    string str = "nitin";
    allSubsequences(str);
    return 0;
}