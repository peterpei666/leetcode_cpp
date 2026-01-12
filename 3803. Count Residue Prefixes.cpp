#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int residuePrefixes(const string& s)
    {
        int n = (int)s.size();
        int mask = 0;
        int ans = 0, cnt = 0;
        for (int i = 0; i < n && cnt < 3; i++)
        {
            if ((mask & (1 << (s[i] - 'a'))) == 0)
            {
                mask |= 1 << (s[i] - 'a');
                cnt++;
            }
            if ((i + 1) % 3 == cnt)
            {
                ans++;
            }
        }
        return ans;
    }
};
