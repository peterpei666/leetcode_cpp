#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    int findFinalValue(vector<int>& nums, int original)
    {
        bitset<1001> mp;
        int n = (int)nums.size();
        for (int i = 0; i < n; i++)
        {
            mp.set(nums[i]);
        }
        while (original <= 1000 && mp.test(original))
        {
            original <<= 1;
        }
        return original;
    }
};
