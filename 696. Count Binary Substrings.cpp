#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countBinarySubstrings(const string& s)
    {
        int n = (int)s.size();
        int stk[100000];
        int sz = 1;
        stk[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                stk[sz - 1]++;
            }
            else
            {
                stk[sz++] = 1;
            }
        }
        int ans = 0;
        for (int i = 1; i < sz; i++)
        {
            ans += min(stk[i - 1], stk[i]);
        }
        return ans;
    }
};
