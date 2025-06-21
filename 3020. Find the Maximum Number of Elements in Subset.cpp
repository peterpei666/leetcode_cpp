#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    int dfs(int cur,int x,unordered_map<int,int>& list)
    {
        if(list.count(x)==false)
        {
            return cur-1;
        }
        if(list[x]==1)
        {
            return cur+1;
        }
        else
        {
            if(x>sqrt(INT_MAX))
            {
                return cur+1;
            }
            else
            {
                return dfs(cur+2,x*x,list);
            }
        }
    }
    
public:
    int maximumLength(vector<int>& nums)
    {
        unordered_map<int,int> list;
        for(int i:nums)
        {
            list[i]++;
        }
        int ans=1;
        if(list[1])
        {
            if(list[1]&1)
            {
                ans=list[1];
            }
            else
            {
                ans=max(ans,list[1]-1);
            }
        }
        list.erase(1);
        for(auto& [x,_]:list)
        {
            ans=max(ans,dfs(0,x,list));
        }
        return ans;
    }
};
