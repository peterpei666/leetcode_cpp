#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int>& nums, int k)
    {
        const int mod=1e9+7;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i:nums)
        {
            pq.push(i);
        }
        while(k)
        {
            int temp=pq.top();
            pq.pop();
            pq.push(temp+1);
            k--;
        }
        long long ret=1;
        while(!pq.empty())
        {
            ret*=pq.top();
            pq.pop();
            ret%=mod;
        }
        return ret%mod;
    }
};
