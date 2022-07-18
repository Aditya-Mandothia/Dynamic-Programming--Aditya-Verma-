#include <bits/stdc++.h>
using namespace std;

bool solve(string a, string b)
{
    if (a.compare(b) == 0)
    {
        return true;
    }

    if (a.length() <= 1)
        return false; // unequal strings can never be scrambled strings

    bool flag = false;

    int n = a.length();

    for (int i = 1; i <= n - 1; i++)
    {
        bool A = solve(a.substr(0, i), b.substr(n - i, i)) && solve(a.substr(i, n - i), b.substr(0, n - i));
        bool B = solve(a.substr(0, i), b.substr(n - i, i)) && solve(a.substr(i, n - i), b.substr(0, n - i));

        if (A || B)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

int main()
{
    string a = "great";
    string b = "great";

    if(a.length() != b.length())
    {
        return false;
    }

    if(a.length() == 0 and b.length() == 0)
    {
        return true;
    }

    solve(a,b);

    return 0;
}