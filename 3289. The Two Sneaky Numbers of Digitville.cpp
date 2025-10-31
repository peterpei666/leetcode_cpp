#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    vector<int> getSneakyNumbers(vector<int>& nums)
    {
        int n = (int)nums.size();
        bitset<100> mp;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (mp.test(nums[i]))
            {
                ans.push_back(nums[i]);
            }
            else
            {
                mp.set(nums[i]);
            }
        }
        return ans;
    }
};
