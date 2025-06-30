#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findLHS(vector<int>& nums)
    {
        unordered_map<int,int> mp;
        for(int i:nums)
        {
            mp[i]++;
        }
        int ans=0;
        for(auto& [x,n]:mp)
        {
            if(mp.count(x+1))
            {
                ans=max(ans,n+mp[x+1]);
            }
        }
        return ans;
    }
};
