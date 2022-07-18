#include <bits/stdc++.h>
using namespace std;

int static t[6][6];

int solve(int arr[], int i, int j)
{
    if (i >= j)
    {
        return 0;
    }

    if(t[i][j]!=-1)
    return t[i][j];

    int mn = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = solve(arr, i, k) + solve(arr, k+1, j) + arr[i - 1] * arr[k] * arr[j];

        
            mn = min(mn, temp);
    }

    return t[i][j] = mn;
}

int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    int i = 1, j = 4;

    memset(t,-1,sizeof(t));

    cout << solve(arr, i, j);
    return 0;
}