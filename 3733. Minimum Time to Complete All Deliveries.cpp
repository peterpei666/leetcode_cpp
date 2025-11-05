#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    long long minimumTime(vector<int>& a, vector<int>& b)
    {
        long long t = (1LL * b[0] * b[1]) / gcd(b[0], b[1]);
        long long l = 1LL * a[0] + 1LL * a[1];
        long long r = 2LL * INT_MAX;
        while (l < r)
        {
            long long mid = (l + r) / 2;
            long long t4 = mid / t;
            long long t2 = mid / b[1] - t4;
            long long t3 = mid / b[0] - t4;
            long long t1 = mid - t2 - t3 - t4;
            if (t1 < max(0LL, a[0] - t2) + max(0LL, a[1] - t3))
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }
};
