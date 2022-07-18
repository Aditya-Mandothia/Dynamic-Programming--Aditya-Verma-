#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> mp;

int solve(string s, int i, int j, bool isTrue)
{
    if (i > j)
        return false;

    if (i == j)
    {
        if (isTrue == true)
            return s[i] == 'T';

        else
            return s[i] == 'F';
    }

    string temp = to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(isTrue));

    //from here the temp strinf is created for the map.

    if (mp.find(temp) != mp.end())
    {
        return mp[temp];
    }

    int ans = 0;

    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int lt = solve(s, i, k - 1, true);
        int lf = solve(s, i, k - 1, false);
        int rt = solve(s, k + 1, j, true);
        int rf = solve(s, k + 1, j, false);

        if (s[k] == '&')
        {
            if (isTrue == true)
            {
                ans = ans + lt * rt;
            }
            else
            {
                ans = ans + lf * rt + lt * rf + lf * rf;
            }
        }
        else if (s[k] == '|')
        {
            if (isTrue == true)
            {
                ans = ans + lt * rf + lf * rt + lt * rt;
            }
            else
            {
                ans = ans + lf + rf;
            }
        }
        else if (s[k] == '^')
        {
            if (isTrue == true)
            {
                ans = ans + lf * rt + lt * rf;
            }
            else
            {
                ans = ans + lt * rt + lf * rf;
            }
        }
    }

    return mp[temp] = ans;
}
int main()
{
    mp.clear();

    string s = "T|F&T^F";
    int i = 0;
    int j = s.size() - 1;
    cout << solve(s, i, j, true);

    return 0;
}