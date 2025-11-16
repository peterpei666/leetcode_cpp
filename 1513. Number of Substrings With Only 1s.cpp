#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numSub(const string& s)
    {
        int ans = 0, cnt = 0;
        const int mod = 1e9 + 7;
        for (auto& c : s)
        {
            if (c == '0')
            {
                ans = (ans + 1LL * cnt * (cnt + 1) / 2) % mod;
                cnt = 0;
            }
            else
            {
                cnt++;
            }
        }
        return (ans + 1LL * cnt * (cnt + 1) / 2) % mod;
    }
};
