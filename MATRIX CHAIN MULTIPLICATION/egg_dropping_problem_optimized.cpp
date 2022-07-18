#include <bits/stdc++.h>
using namespace std;

int t[6][4];

int solve(int f, int e)
{
   if(f==0 || f==1)
   {
       return f;
   }

   if(e==1)
   {
       return f;
   }

    if(t[f][e]!=-1)
    return t[f][e];

    int ans = INT_MAX;

    for(int k = 1; k <= f; k++)
    {   
        int low=0,high=0;

        if(t[k-1][e-1]!=-1)
        low = t[k-1][e-1];
        else
        low = t[k-1][e-1] = solve(k-1,e-1);

        if(t[f-k][e]!=-1)
        high = t[f-k][e];
        else
        high = t[f-k][e] = solve(f-k,e);
        

        int temp = 1 + max(low,high);

        ans = min(temp,ans);
    }

    return t[f][e] = ans;
}
int main()
{
    int f = 5, e = 3;
    memset(t,-1,sizeof(t));


    cout<<solve(f,e);

    return 0;
}