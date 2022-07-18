#include <bits/stdc++.h>
using namespace std;

int t[7][8];

int main()
{
    string x = "abcdgh", y = "abcdfhr";

    int n = 6, m = 7;
    int ans = 0;

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
                ans = max(ans,t[i][j]);
            }
            else
            {
                t[i][j] = 0;

            }
        }

    cout << "The LCS size is :" << ans << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << t[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}