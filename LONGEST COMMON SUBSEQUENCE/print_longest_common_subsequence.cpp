#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int t[7][8];

int main()
{
    string x = "abcdgh", y = "abedfhr";

    int n = 6, m = 7;

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
            c = c + x[i - 1];
            i--;
            j--;
        }
        else
        {

            if (t[i - 1][j] > t[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }

    cout<<"\n THE LCS IS : ";

    int k= c.size()-1;
    while(k>=0)
    {
        cout<<c[k];
        k--;
    }

    return 0;
}