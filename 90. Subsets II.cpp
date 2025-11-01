#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> mp;
        for (int mask = 0; mask < (1 << n); mask++)
        {
            vector<int> temp;
            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                {
                    temp.push_back(nums[i]);
                }
            }
            mp.insert(temp);
        }
        return vector<vector<int>>(mp.begin(), mp.end());
    }
};
