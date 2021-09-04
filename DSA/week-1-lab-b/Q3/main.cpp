/*
Q.3. Use STL APIs to
a. sort a numeric array and a string array
b. calculate the average, min, max value of array elements
c. test if an array contains a specific value
d. find the index of a given array element
e. remove a specific element from an array
f. insert an element (specific position) into an array
g. find the duplicate values of an array of integer values and another array of string values
h. find the common elements between two arrays (string values)
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_set>

using namespace std;
int main()
{
    vector<int> v1 = {598, 324, 5664, 23, 1};
    vector<string> v2 = {"ab", "abc", "ad", "abab", "ab"};
    vector<int> v3 = {598, 324, 5664, 23, 1};
    vector<int> v4 = {598, 324, 5664, 23, 1, 23, 324};
    vector<string> v5 = {"abc", "abab", "cb", "cd"};

    //SORT numeric array
    cout << "Sorted numeric array: ";
    sort(v1.begin(), v1.end());
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";
    cout << endl;

    //SORT string array
    cout << "Sorted string array: ";
    sort(v2.begin(), v2.end());
    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";
    cout << endl;

    //Search for element
    if (find(v3.begin(), v3.end(), 23) != v3.end())
        cout << "Found 23";
    else
        cout << "Not Found 23";
    cout << endl;

    //Find Index of element
    auto it = find(v3.begin(), v3.end(), 23);
    if (it != v3.end())
        cout << "Found 23 at index " << it - v3.begin();
    else
        cout << "23 not found!";
    cout << endl;

    //Delete an element
    int index = 3;
    it = v4.begin() + index;
    v4.erase(it);
    cout << "New array after erasing the 3rd element: ";
    for (int i = 0; i < v4.size(); i++)
        cout << v4[i] << " ";
    cout << endl;

    //Inserting an element
    cout << "New array after inserting 500";
    v4.insert(v4.begin() + 3, 500);
    for (int i = 0; i < v4.size(); i++)
        cout << v4[i] << " ";
    cout << endl;

    //finding duplicate elements in int
    v4 = {1, 6, 6, 10, 4, 2, 2, 8, 8};
    cout << "Repeated elements are: ";
    unordered_set<int> st;
    for (int i = 0; i < v4.size(); i++)
    {
        if (st.find(v4[i]) == st.end())
            st.insert(v4[i]);
        else
            cout << v4[i] << " ";
    }

    //finding duplicate elements string
    v2 = {"cat", "dog", "cat", "pet", "apple", "apple"};
    cout << "\nRepeated elements are: ";
    unordered_set<string> st_new;
    for (int i = 0; i < v2.size(); i++)
    {
        if (st_new.find(v2[i]) == st_new.end())
            st_new.insert(v2[i]);
        else
            cout << v2[i] << " ";
    }

    //find the common elements between two arrays (string values)
    cout << endl;
    cout << "Repeated elements are: ";
    unordered_set<string> set;
    for (int i = 0; i < v2.size(); i++)
        set.insert(v2[i]);

    for (int i = 0; i < v5.size(); i++)
    {
        if (set.find(v5[i]) != set.end())
            cout << v5[i] << " ";
    }
    return 0;
}