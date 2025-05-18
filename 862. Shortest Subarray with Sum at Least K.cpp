#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

class Solution
{
public:
    int shortestSubarray(vector<int>& nums, int k)
    {
        int ret=INT_MAX;
        long long cur=0;
        deque<pair<long long,int>> q;
        for(int i=0;i<nums.size();i++)
        {
            cur+=nums[i];
            if(cur>=k)
            {
                ret=min(ret,i+1);
            }
            while(!q.empty()&&cur-q.front().first>=k)
            {
                ret=min(ret,i-q.front().second);
                q.pop_front();
            }
            while(!q.empty()&&q.back().first>cur)
            {
                q.pop_back();
            }
            q.push_back({cur,i});
        }
        return ret==INT_MAX?-1:ret;
    }
};
