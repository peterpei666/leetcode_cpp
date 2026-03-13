#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    inline long long get(long long x, long long t)
    {
        return (sqrt(8 * (x / t) + 1) - 1) / 2;
    }
    
    bool check(long long x, vector<int>& workerTimes, int mountainHeight)
    {
        long long cur = 0;
        for (int i : workerTimes)
        {
            cur += get(x, i);
            if (cur >= mountainHeight)
            {
                return true;
            }
        }
        return false;
    }
    
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes)
    {
        long long l = 0, r = 1e18;
        long long ans = -1;
        while (l <= r)
        {
            long long mid = l + (r - l) / 2;
            if (check(mid, workerTimes, mountainHeight))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};
