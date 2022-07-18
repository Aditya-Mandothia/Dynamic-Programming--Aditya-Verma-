#include <bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int val[], int W, int n)
{

    if (W == 0 || n == 0)
    {
        return 0;
    }

    if (wt[n - 1] <= W)
    {
        return max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), knapsack(wt, val, W, n - 1));
    }
    else if (wt[n - 1] > W)
    {
        return knapsack(wt, val, W, n - 1);
    }
}

int main()
{
    int Wt[] = {1, 3, 6, 9};
    int Val[] = {2, 6, 3, 10};

    int W = 15;
    int n = sizeof(Wt) / sizeof(int);

    cout << knapsack(Wt, Val, W, n);

    return 0;
}