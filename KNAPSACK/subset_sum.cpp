#include <bits/stdc++.h>
using namespace std;

bool t[5][12];
int main()
{
    int a[] = {1, 5, 3, 5};
    int n = 4;
    int sum = 11;

    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < sum + 1; j++)
            if (i == 0)
                t[i][j] = false;
            else if (j == 0)
                t[i][j] = true;

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < sum + 1; j++)
        {
            if (a[i - 1] <= j)
                t[i][j] = t[i][j - a[i - 1]] || t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        }

    cout<<"THE POSSIBILITY IS : "<<t[n][sum];

    return 0;
}