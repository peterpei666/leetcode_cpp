#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    int reversePairs(vector<int>& nums)
    {
        int n = (int)nums.size();
        int fenwick[n + 1];
        memset(fenwick, 0, sizeof(fenwick));
        int temp[n];
        memcpy(temp, &nums[0], sizeof(int) * n);
        sort(&temp[0], &temp[0] + n);
        
        function<int(int)> query = [&](int i)
        {
            int ans = 0;
            while (i > 0)
            {
                ans += fenwick[i];
                i -= i & (-i);
            }
            return ans;
        };
        
        function<void(int, int)> update = [&](int i, int x)
        {
            while (i <= n)
            {
                fenwick[i] += x;
                i += i & (-i);
            }
        };
        
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int idx = (int)(lower_bound(&temp[0], &temp[0] + n, 2LL * nums[i] + 1) - &temp[0]) + 1;
            ans += query(n) - query(idx - 1);
            int updateIdx = (int)(lower_bound(&temp[0], &temp[0] + n, nums[i]) - &temp[0]) + 1;
            update(updateIdx, 1);
        }
        return ans;
    }
};
