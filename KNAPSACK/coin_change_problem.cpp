// In this question we have to find the minimum number of coins used to reach a sum and we have to tell the amount of ways

#include <bits/stdc++.h>
using namespace std;

int t[4][6];

int main()
{

    int coin[] = {1, 2, 3};

    int sum = 5;
    int n = 3;

    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
                t[i][j] = 0;

            if(i==0)
            t[i][j]= INT_MAX - 1;
        }

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < sum + 1; j++)
        {
            if (coin[i - 1] <= j)
            {
                t[i][j] = min(t[i][j - coin[i - 1]] + 1, t[i - 1][j]);
            }
            else if (coin[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            }
        }

    cout << "no. of ways are  : " << t[n][sum];

    return 0;
}