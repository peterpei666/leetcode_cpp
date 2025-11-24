#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<bool> prefixesDivBy5(vector<int>& nums)
    {
        int n = (int)nums.size();
        vector<bool> ans(n);
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            temp = ((temp << 1) + nums[i]) % 5;
            ans[i] = !temp;
        }
        return ans;
    }
};
