#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int>& primes)
    {
        int m = (int)primes.size();
        long long ugly[n];
        long long next[m];
        int idx[m];
        memset(idx, 0, sizeof(idx));
        ugly[0] = 1;
        for (int i = 0; i < m; i++)
        {
            next[i] = primes[i];
        }
        for (int i = 1; i < n; i++)
        {
            long long t = INT_MAX;
            for (int j = 0; j < m; j++)
            {
                t = min(t, next[j]);
            }
            ugly[i] = t;
            for (int j = 0; j < m; j++)
            {
                if (next[j] == t)
                {
                    idx[j]++;
                    next[j] = primes[j] * ugly[idx[j]];
                }
            }
        }
        return (int)ugly[n - 1];
    }
};
