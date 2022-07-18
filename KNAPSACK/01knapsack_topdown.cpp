#include <bits/stdc++.h>
using namespace std;

int t[5][16];

int main()
{

    int wt[] = {1, 3, 6, 9};
    int val[] = {2, 6, 3, 10};

    int w = 15;
    int n = 4;

    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < w + 1; j++)
            if (i == 0 || j == 0)
                t[i][j] = 0;

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], 0 + t[i - 1][j]);
            }
            else if(wt[i-1]>j)
            {
                t[i][j] = t[i - 1][j];
            }
        }

    cout << "MAX PROFIT : " << t[n][w];

    return 0;
}