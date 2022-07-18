#include <bits/stdc++.h>
using namespace std;

bool t[5][24];

int main()
{
    int arr[] = {1, 6, 11, 5};

    int range = 0;
    for (int i = 0; i < 4; i++)
    {
        range += arr[i];
    }

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 24; j++)
        {
            if (i == 0)
                t[i][j] = 0;

            if (j == 0)
                t[i][j] = 1;
        }

    for (int i = 1; i < 5; i++)
        for (int j = 1; j < 24; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }

    int ans = INT_MAX;

    for (int j = 0; j <=range; j++)
    {
        if (t[4][j])
        {
            ans = min(ans,abs(range - 2 * j));
        }
    }

    cout << "The answer is : " << ans << endl;

    return 0;
}