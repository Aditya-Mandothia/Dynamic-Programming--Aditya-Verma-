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
        int temp = 1 + max(solve(k-1,e-1),solve(f-k,e));
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