#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int centeredSubarrays(vector<int>& nums)
    {
        int n = (int)nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> mp;
            int total = 0;
            for (int j = i; j < n; j++)
            {
                mp.insert(nums[j]);
                total += nums[j];
                if (mp.count(total))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
