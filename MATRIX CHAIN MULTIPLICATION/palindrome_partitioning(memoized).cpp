#include <bits/stdc++.h>
using namespace std;

int t[7][7];

int ispalindrome(string s, int i, int j)
{
    int counter = 0;

    int size = j - i + 1;
    for (int a = 0; a < size / 2; a++)
    {
        if (s[a] == s[size - a - 1])
        {
            continue;
        }
        else
            counter++;
    }

    return counter;
}

int solve(string s, int i, int j)
{
    if (i >= j)
    {
        return 0;
    }

    if (ispalindrome(s, i, j) == 0)
        return 0;

    if(t[i][j]!=-1)
    {
        return t[i][j];
    }

    int mn = INT_MAX;

    for (int k = i; k <= j - 1; k++)
    {
        int temp = solve(s, i, k) + solve(s, k + 1, j) + 1;

        mn = min(mn, temp);
    }

    return t[i][j] = mn;
}

int main()
{

    string s = "nitina";

    memset(t,-1,sizeof(t));

    int i = 0, j = s.size() - 1;

    cout << solve(s, i, j);

    return 0;
}