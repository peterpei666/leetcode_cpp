#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> list;
        sort(nums.begin(),nums.end());
        do
        {
            list.push_back(nums);
        } while (next_permutation(nums.begin(),nums.end()));
        return list;
    }
};
