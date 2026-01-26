#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumPrefixLength(vector<int>& nums)
    {
        int n = (int)nums.size() - 1;
        while (n > 0 && nums[n] > nums[n - 1])
        {
            n--;
        }
        return n;
    }
};
