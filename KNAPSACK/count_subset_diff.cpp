#include <bits/stdc++.h>
using namespace std;

int t[5][8];

int main()
{
    int arr[] = {1, 1, 2, 3};
    int dif = 1;

    int range = 0;
    for (int i = 0; i < 4; i++)
    {
        range += arr[i];
    }

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 8; j++)
        {
            if (i == 0)
                t[i][j] = 0;

            if (j == 0)
                t[i][j] = 1;
        }

    for (int i = 1; i < 5; i++)
        for (int j = 1; j < 8; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }



    cout << "The answer is : " << t[4][(dif+range)/2] << endl;

    return 0;
}