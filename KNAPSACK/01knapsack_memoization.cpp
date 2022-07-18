#include <bits/stdc++.h>
using namespace std;

int t[5][16];

int knapsack(int wt[], int val[], int W, int n)
{

    if (W == 0 || n == 0)
    {
        return 0;
    }

    if (t[n][W] != -1)
    {
        return t[n][W];
    }

    if (wt[n - 1] <= W)
    {
        return t[n][W] = max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), knapsack(wt, val, W, n - 1));
    }
    else if (wt[n - 1] > W)
    {
        return t[n][W] = knapsack(wt, val, W, n - 1);
    }
}

int main()
{
    memset(t, -1, sizeof(t));

    int Wt[] = {1, 3, 6, 9};
    int Val[] = {2, 6, 3, 10};

    int W = 15;
    int n = sizeof(Wt) / sizeof(int);

    cout << knapsack(Wt, Val, W, n);

    return 0;
}