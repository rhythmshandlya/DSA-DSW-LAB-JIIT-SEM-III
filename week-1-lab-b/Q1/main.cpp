/*
Q.1. Write a program with and without STL that prompts the user for an integer, then asks the
user to enter that many values.
a. Store these values in an array and print the array.
b. Then reverse the array elements so that the first element becomes the last element, the second
element becomes the second to last element, and so on, with the old last element now first. Do
not just reverse the order in which they are printed; actually change the way they are stored in
the array. Do not create a second array; just rearrange the elements within the array you have.
(Hint: Swap elements that need to change places.)
c. When the elements have been reversed, print the array again.
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long int lli;

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    //TAKE INPUT AND PRINT
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    //REVERSE THE ARRAY
    for (int i = 0; i < n / 2; i++)
        swap(arr[i], arr[n - i - 1]);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    cout << endl;
    system("pause");
    return 0;
}