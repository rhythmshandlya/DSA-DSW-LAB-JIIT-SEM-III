#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v1{1, 2, 3, 6, 7, 8, 9};
    vector<int> v2{4, 5};

    v1.insert(v1.begin() + 3, v2.begin(), v2.end());
    for (int i : v1)
        cout << i << " ";
    cout << endl;

    v1.insert(v1.end(), 10);
    for (int i : v1)
        cout << i << " ";
    cout << endl;

    fill(v1.begin() + 5, v1.end(), 5);
    for (int i : v1)
        cout << i << " ";
    cout << endl;

    return 0;
}