#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumCost(vector<int>& nums)
    {
        int n = (int)nums.size();
        int m1 = INT_MAX;
        int m2 = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] <= m1)
            {
                m2 = m1;
                m1 = nums[i];
            }
            else if (nums[i] < m2)
            {
                m2 = nums[i];
            }
        }
        return nums[0] + m1 + m2;
    }
};
