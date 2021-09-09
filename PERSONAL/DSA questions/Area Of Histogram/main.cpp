#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

static int x = 37;
void rotate90(vector<vector<int>> &arr, int n)
{
    int i = 0;
    arr[0][0] = 0;
}
int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = arr[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    rotate90(arr, n);
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}