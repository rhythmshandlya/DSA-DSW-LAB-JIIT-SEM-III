/*
Q.2. Write following methods using STL APIs for arrays. Also, write the methods, and add
code to the main method to test them thoroughly. Place all of these in the
provided CustomArray class. Note that your methods should not print their answers. Instead,
they should return their answers so they can be printed by your test cases in main.
a. Write a method sum that takes an array of double values as its parameter and returns
the sum of all elements in the array.
b. Write a method sum that takes an array of int values as its parameter and returns the
sum of all elements in the array.
c. Write a method largest that takes an array of int values as its parameter and returns the
value of the largest element in the array.
d. Write a method countLarger that takes an array of int values and an additional int as its
parameters, and returns the number of entries in the array that are at least as large as the
additional int.
e. Write a method countTrues that takes an array of boolean values as its parameter and
returns the number of entries that contain true.
f. Write a method stringLengths that takes an array of String values as its parameter and
returns an array of int that contains the lengths of those Strings. That is, each element
in the returned array contains the length of the String in the corresponding element of
the parameter array.
*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;
typedef long long int lli;

int getSum(vector<double> &arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
        sum += arr[i];
    return sum;
}
int getLargest(vector<int> &vec)
{
    int largest = INT_MIN;
    for (int i = 0; i < vec.size(); i++)
    {
        largest = max(largest, vec[i]);
    }
    return largest;
}
int isGreaterThan(vector<int> &v, int n)
{
    int count = 0;
    for (int i = 0; i < v.size(); i++)
        if (n <= v[i])
            count++;
    return count;
}
int areTrue(vector<bool> &v)
{
    int count = 0;
    for (int i = 0; i < v.size(); i++)
        if (v[i])
            count++;
    return count;
}

vector<int> getSizeArray(vector<string> v)
{
    vector<int> count;
    for (int i = 0; i < v.size(); i++)
    {
        count.push_back(v[i].length());
    }
    return count;
}

int main()
{
    vector<double> sum = {1.5, 2.6, 3.7, 4.8, 5.9};
    cout << "Sum: " << getSum(sum) << "\n";

    vector<int> large = {1, 23, 556, 34, 2343};
    cout << "Largest: " << getLargest(large) << "\n";

    vector<int> larger = {
        1,
        3,
        5,
        6,
        7,
    };
    int n = 5;
    cout << "Larger than " << n << ":" << isGreaterThan(larger, n) << "\n";

    vector<bool> areTru = {true, true, false, false, true, true};
    cout << "Total true: " << areTrue(areTru) << "\n";

    cout << "Size of strings: ";
    vector<string> length = {"rhythm", "shandilya", "yes", "no"};
    vector<int> sizes = getSizeArray(length);
    for (int i = 0; i < sizes.size(); i++)
    {
        cout << sizes[i] << " ";
    }
    cout << endl;
    return 0;
}
