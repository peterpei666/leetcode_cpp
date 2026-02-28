#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int concatenatedBinary(int n)
    {
        long long ans = 0;
        const int mod = 1e9 + 7;
        for (int i = 1, len = 0; i <= n; i++)
        {
            if (!(i & (i - 1)))
            {
                len++;
            }
            ans = ((ans << len) + i) % mod;
        }
        return ans % mod;
    }
};
