#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int>& nums)
    {
        int n = (int)nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] != nums[i - 1])
            {
                return 1;
            }
        }
        return 0;
    }
};
