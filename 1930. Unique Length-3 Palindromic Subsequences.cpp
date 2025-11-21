#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    int countPalindromicSubsequence(const string& s)
    {
        int valid = 0;
        int mp[26] = {0};
        int last[26];
        memset(last, -1, sizeof(last));
        int n = (int)s.size();
        for (int i = n - 1, cnt = 0; cnt < 26 && i >= 0; i--)
        {
            if (last[s[i] - 'a'] == -1)
            {
                cnt++;
                last[s[i] - 'a'] = i;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (i == last[s[i] - 'a'])
            {
                valid &= ~(1 << (s[i] - 'a'));
            }
            for (int k = 0; k < 26; k++)
            {
                if (valid & (1 << k))
                {
                    mp[k] |= 1 << (s[i] - 'a');
                }
            }
            if (i != last[s[i] - 'a'])
            {
                valid |= 1 << (s[i] - 'a');
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            ans += (int)__builtin_popcount(mp[i]);
        }
        return ans;
    }
};
