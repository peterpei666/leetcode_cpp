#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    long long maxRunTime(int n, vector<int>& batteries)
    {
        sort(batteries.begin(), batteries.end(), greater<>());
        long long extra = std::accumulate(batteries.begin() + n, batteries.end(), 0LL);
        for (int i = n - 1; i > 0; i--)
        {
            if (extra >= (batteries[i - 1] - batteries[i]) * 1LL * (n - i))
            {
                extra -= (batteries[i - 1] - batteries[i]) * 1LL * (n - i);
            }
            else
            {
                return batteries[i] * 1LL + extra / (n - i);
            }
        }
        return batteries[0] * 1LL + extra / n;
    }
};
