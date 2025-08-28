#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool partitionArray(vector<int>& nums, int k)
    {
        int n = (int)nums.size();
        if (n % k)
        {
            return false;
        }
        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for (auto [x, cnt] : mp)
        {
            if (cnt > n / k)
            {
                return false;
            }
        }
        return true;
    }
};
