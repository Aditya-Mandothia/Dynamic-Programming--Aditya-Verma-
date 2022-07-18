#include <bits/stdc++.h>
using namespace std;

int t[7][8];

int main()
{
    string x = "agbcba", y;
    int a = x.size() - 1;
    int b = 0;
    while (a >= 0)
    {
        y[b] = x[a];
        a--;
        b++;
    }

    int n = 6, m = 7;

    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }

    cout << "The LCS size is :" << t[n][m];

    return 0;
}