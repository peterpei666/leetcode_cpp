#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long countCommas(long long n)
    {
        long long ans = 0;
        for (long long k = 1000; k <= n; k *= 1000)
        {
            ans += max(0LL, n - k + 1);
        }
        return ans;
    }
};
