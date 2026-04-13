#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int getMinDistance(vector<int>& nums, int target, int start)
    {
        int n = (int)nums.size();
        int ans = 10000;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == target)
            {
                ans = min(ans, abs(i - start));
            }
        }
        return ans;
    }
};
