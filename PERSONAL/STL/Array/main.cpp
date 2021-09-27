#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    array<int, 10> arr;

    int i = 0;
    //Iterate using iterator
    for (array<int, 10>::iterator it = arr.begin(); it != arr.end(); i++, it++)
    {
        *it = i;
        cout << *it << " ";
    }
    cout << "\n";

    //Iterate using indexing
    for (int i = 0; i < arr.size(); i++)
        cout << arr.at(i) << " "; //OR arr[i]

    cout << "\n";

    // Fill array with value passed, CANNOT fill in a range
    arr.fill(5);

    //Returns pointer to the first element of the array
    int *ptr = arr.data();

    //Size
    cout << arr.size() << endl;

    //Swaps similar array elements
    array<int, 10> arr_new;
    arr_new.swap(arr);

    cout << "Front: " << arr.front() << endl;
    cout << "Back: " << arr.back() << endl;
    return 0;
}