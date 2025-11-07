#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maxPower(vector<int>& stations, int r, int k)
    {
        int n = (int)stations.size();
        vector<long long> diff(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            diff[max(0, i - r)] += stations[i];
            diff[min(n, i + r + 1)] -= stations[i];
        }

        auto check = [&](long long target) -> bool
        {
            vector<long long> curDiff = diff;
            long long cur = 0, remain = k;
            for (int i = 0; i < n; i++)
            {
                cur += curDiff[i];
                if (cur < target)
                {
                    long long add = target - cur;
                    if (add > remain)
                    {
                        return false;
                    }
                    remain -= add;
                    cur += add;
                    int pos = i + 2 * r + 1;
                    if (pos < n)
                    {
                        curDiff[pos] -= add;
                    }
                }
            }
            return true;
        };

        long long low = 0;
        long long high = k;
        for (int& s : stations)
        {
            high += s;
        }
        while (low < high)
        {
            long long mid = (low + high + 1) / 2;
            if (check(mid))
            {
                low = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};
