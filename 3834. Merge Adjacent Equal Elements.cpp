#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<long long> mergeAdjacent(vector<int>& nums)
    {
        int n = (int)nums.size();
        int sz = 0;
        vector<long long> ans(n);
        for (int i = 0; i < n; i++)
        {
            long long temp = nums[i];
            while (sz && ans[sz - 1] == temp)
            {
                temp <<= 1;
                sz--;
            }
            ans[sz++] = temp;
        }
        ans.resize(sz);
        return ans;
    }
};
