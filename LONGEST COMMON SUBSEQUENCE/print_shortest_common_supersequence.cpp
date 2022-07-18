#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int t[7][6];

int main()
{
    string x = "abcdaf", y = "acbcf";

    int n = 6, m = 5;

    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }

    // memset(t,0,sizeof(t));

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

    int i = n, j = m;
    string c;

    while (i > 0 and j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            c.push_back(x[i-1]);
            i--;
            j--;
        }
        else
        {

            if (t[i - 1][j] > t[i][j - 1])
            {
                c.push_back(x[i-1]);
                i--;
            }
            else if (t[i - 1][j] < t[i][j - 1])
            {
                c.push_back(y[j-1]);
                j--;
            }
        }
    }

    while (i > 0)
    {
        c = c + x[i - 1];
        i--;
    }

    while (j > 0)
    {
        c = c + y[j - 1];
        j--;
    }

    cout << "\n THE SCS IS : ";

   int k = n+m-t[n][m];

   for(k;k>=0;k--)
   {
       cout<<c[k];
   }

    return 0;
}