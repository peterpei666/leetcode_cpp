#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int>& nums, int k)
    {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(int i:nums)
        {
            pq.push(i);
        }
        int c=0;
        while(pq.size()>=2&&pq.top()<k)
        {
            long long m,n;
            m=pq.top();
            pq.pop();
            n=pq.top();
            pq.pop();
            pq.push(2*min(m,n)+max(m,n));
            c++;
        }
        return c;
    }
};
