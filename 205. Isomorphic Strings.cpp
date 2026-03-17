#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(const string& s, const string& t)
    {
        char mp[128] = {0};
        int n = (int)s.size();
        for (int i = 0; i < n; i++)
        {
            if (mp[s[i]] == 0)
            {
                mp[s[i]] = t[i];
            }
            if (mp[s[i]] != t[i])
            {
                return false;
            }
        }
        bool found[128] = {false};
        for (int i = 0; i < 127; i++)
        {
            if (mp[i] && found[mp[i]])
            {
                return false;
            }
            found[mp[i]] = true;
        }
        return true;
    }
};
