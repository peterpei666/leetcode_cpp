#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string smallestPalindrome(const string& s)
    {
        int n = (int)s.size();
        int mp[26] = {0};
        for (int i = 0; i < n; i++)
        {
            mp[s[i] - 'a']++;
        }
        string ans;
        int odd = -1;
        for (int i = 0; i < 26; i++)
        {
            while (mp[i] > 1)
            {
                mp[i] -= 2;
                ans += 'a' + i;
            }
            if (mp[i])
            {
                odd = i;
            }
        }
        string temp = ans;
        reverse(temp.begin(), temp.end());
        if (odd == -1)
        {
            return ans + temp;
        }
        return ans + (char)('a' + odd) + temp;
    }
};
