#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
    int minGroups(vector<vector<int>>& intervals)
    {
        map<int,int> mp;
        for(auto& interval:intervals)
        {
            mp[interval[0]]++;
            mp[interval[1]]--;
        }
        int ans=0,temp=0;
        for(auto& [x,n]:mp)
        {
            temp+=n;
            ans=max(ans,temp);
        }
        return ans;
    }
};
