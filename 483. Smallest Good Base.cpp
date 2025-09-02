#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    long long cal(long long base, int k)
    {
        long long ans = 1;
        long long cur = 1;
        for (int i = 1; i < k; i++)
        {
            if (cur > LLONG_MAX / base)
            {
                return LLONG_MAX;
            }
            cur *= base;
            if (ans > LLONG_MAX - cur)
            {
                return LLONG_MAX;
            }
            ans += cur;
        }
        return ans;
    }
    
public:
    string smallestGoodBase(const string& n)
    {
        long long m = stoll(n);
        int k = 0;
        while (m)
        {
            m /= 2;
            k++;
        }
        m = stoll(n);
        for (int i = k; i >= 2; i--)
        {
            long long l = 2;
            long long r = ceil(pow(m, 1.0 / (i - 1))) + 1;
            while (l <= r)
            {
                long long mid = (l + r) / 2;
                long long sum = cal(mid, i);
                if (sum == m)
                {
                    return to_string(mid);
                }
                else if (sum < m)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        return to_string(m - 1);
    }
};
