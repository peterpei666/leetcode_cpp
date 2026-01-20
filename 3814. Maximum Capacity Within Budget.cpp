#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget)
    {
        int n = (int)costs.size();
        vector<long long> t(n);
        for (int i = 0; i < n; i++)
        {
            t[i] = (long long)costs[i] << 32 | capacity[i];
        }
        sort(t.begin(), t.end());
        vector<int> pre(n);
        for (int i = 0, m = 0; i < n; i++)
        {
            m = max(m, (int)t[i]);
            pre[i] = m;
        }
        int ans = 0;
        for (int i = 0, j = n - 1; i < n; i++)
        {
            int c = (int)(t[i] >> 32);
            int v = (int)t[i];
            if (c < budget)
            {
                ans = max(ans, v);
            }
            while (j >= 0 && (t[j] >> 32) + c >= budget)
            {
                j--;
            }
            int k = min(i - 1, j);
            if (k >= 0)
            {
                ans = max(ans, v + pre[k]);
            }
        }
        return ans;
    }
};
