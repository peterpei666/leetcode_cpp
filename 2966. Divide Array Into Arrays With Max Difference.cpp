#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k)
    {
        sort(nums.begin(),nums.end());
        int n=(int)nums.size();
        vector<vector<int>> ret;
        for(int i=0;i<n;i+=3)
        {
            if(nums[i+2]-nums[i]>k)
            {
                ret.clear();
                return ret;
            }
            else
            {
                ret.push_back({nums[i],nums[i+1],nums[i+2]});
            }
        }
        return ret;
    }
};
