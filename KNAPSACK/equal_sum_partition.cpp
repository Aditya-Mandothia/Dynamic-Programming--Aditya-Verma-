#include <bits/stdc++.h>
using namespace std;

int t[5][23];

bool subset_sum(vector<int> &a, int n, int sum)
{

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

    return t[n][sum];
}

bool equal_sum(vector<int> &a, int n)
{
    
    int sum = 0;
    for (int i = 0; i < a.size() - 1; i++)
        sum = sum + a[i];

    if (sum % 2 != 0)
        return false;

    else if (sum % 2 == 0)
    {
        return subset_sum(a, n, sum / 2);
    }
}

int main()
{
    vector<int> a = {1, 5, 11, 5};
    int n = a.size();

    cout << equal_sum(a, n);
    return 0;
}