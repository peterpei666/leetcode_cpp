#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int digit(int x)
    {
        int ret=0;
        while(x)
        {
            ret+=x%10;
            x/=10;
        }
        return ret;
    }
    
    int maximumSum(vector<int>& nums)
    {
        unordered_map<int,pair<int,int>> list;
        for(int i:nums)
        {
            int d=digit(i);
            if(i>list[d].first)
            {
                list[d].second=list[d].first;
                list[d].first=i;
            }
            else if(i>list[d].second)
            {
                list[d].second=i;
            }
        }
        int m=-1;
        for(auto& [_,p]:list)
        {
            if(p.first&&p.second)
            {
                m=max(m,p.first+p.second);
            }
        }
        return m;
    }
};
