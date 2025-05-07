#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int rangeSum(vector<int>& nums, int n, int left, int right)
    {
        const int MOD=1e9+7;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++)
        {
            pq.push({nums[i],i});
        }
        int sum=0;
        for(int i=1;i<=right;i++)
        {
            auto [m,id]=pq.top();
            pq.pop();
            if(i>=left)
            {
                sum+=m;
                sum%=MOD;
            }
            if(id+1<n)
            {
                id++;
                m+=nums[id];
                pq.push({m,id});
            }
        }
        return sum;
    }
};
