#include <bits/stdc++.h>
using namespace std;

int t[7][8];

int LCS(string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;

    if (t[n][m] = !-1)
    {
        return t[n][m];
    }

    if (x[n - 1] == y[m - 1])
    {
        return t[n][m] = 1 + LCS(x, y, n - 1, m - 1);
    }
    else
    {
        return t[n][m] = max(LCS(x, y, n, m - 1), LCS(x, y, n - 1, m));
    }
}

int main()
{
    memset(t, -1, sizeof(t));

    string x = "abcdgh", y = "abedfhr";

    cout << "LCS SIZE IS : " << LCS(x, y, 6, 7);

    return 0;
}