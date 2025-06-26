#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestEqualSubarray(vector<int>& nums, int k)
    {
        unordered_map<int,vector<int>> list;
        for(int i=0;i<nums.size();i++)
        {
            list[nums[i]].push_back(i);
        }
        int ans=0;
        for(auto& [_,idx]:list)
        {
            int i=0,j=0;
            int n=(int)idx.size();
            for(i=0;i<n&&j<n;i++)
            {
                while(j<n&&idx[j]-idx[i]-j+i<=k)
                {
                    j++;
                }
                ans=max(ans,j-i);
            }
        }
        return ans;
    }
};
