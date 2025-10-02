#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        set<vector<int>> mp;
        sort(nums.begin(), nums.end());
        mp.insert(nums);
        while (next_permutation(nums.begin(), nums.end()))
        {
            mp.insert(nums);
        }
        vector<vector<int>> ans;
        for (auto& p : mp)
        {
            ans.push_back(p);
        }
        return ans;
    }
};
