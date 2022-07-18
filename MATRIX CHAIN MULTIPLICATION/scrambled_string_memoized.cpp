#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> mp;

bool solve(string a, string b)
{
    if (a.compare(b) == 0)
    {
        return true;
    }

    if (a.length() <= 1)
        return false; // unequal strings can never be scrambled strings

    string key = a;
    key.push_back(' ');
    key.append(b);

    if(mp.find(key)!= mp.end())
    return mp[key];

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
    return mp[key] = flag;
}

int main()
{
    mp.clear();

    string a = "great";
    string b = "great";

    if (a.length() != b.length())
    {
        return false;
    }

    if (a.length() == 0 and b.length() == 0)
    {
        return true;
    }

    cout<<solve(a, b);

    return 0;
}