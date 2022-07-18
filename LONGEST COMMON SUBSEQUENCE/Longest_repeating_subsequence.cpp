#include <bits/stdc++.h>
using namespace std;

int t[8][8];

int main()
{
    string x = "aabdbcc", y = "aabdbcc";

    int n = 7, m = 7;

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
            if (x[i - 1] == y[j - 1] && i!=j)
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }

    cout << "The LRS size is :" << t[n][m];

    return 0;
}