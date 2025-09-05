#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minOperations(const string& s, int k)
    {
        int n = (int)s.size();
        int n0 = 0;
        for (char c : s)
        {
            if (c == '0')
            {
                n0++;
            }
        }
        if (n0 == 0)
        {
            return 0;
        }
        int n1 = n - n0;
        for (long long i = 1; i <= n; i++)
        {
            long long p = i * k;
            if ((p - n0) % 2)
            {
                continue;
            }
            if (i % 2)
            {
                if (p >= n0 && p <= n0 * i + n1 * (i - 1))
                {
                    return (int)i;
                }
            }
            else
            {
                if (p >= n0 && p <= n0 * (i - 1) + n1 * i)
                {
                    return (int)i;
                }
            }
        }
        return -1;
    }
};
