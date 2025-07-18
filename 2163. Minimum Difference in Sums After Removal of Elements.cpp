#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    long long minimumDifference(vector<int>& nums)
    {
        int n=(int)nums.size()/3;
        priority_queue<int> pq1;
        long long sum1=0;
        for(int i=0;i<n;i++)
        {
            pq1.push(nums[i]);
            sum1+=nums[i];
        }
        long long left[n+1];
        left[0]=sum1;
        for(int i=n;i<2*n;i++)
        {
            pq1.push(nums[i]);
            sum1+=nums[i]-pq1.top();
            pq1.pop();
            left[i-n+1]=sum1;
        }
        priority_queue<int,vector<int>,greater<int>> pq2;
        long long sum2=0;
        for(int i=3*n-1;i>=2*n;i--)
        {
            pq2.push(nums[i]);
            sum2+=nums[i];
        }
        long long ans=left[n]-sum2;
        for(int i=2*n-1;i>=n;i--)
        {
            pq2.push(nums[i]);
            sum2+=nums[i]-pq2.top();
            pq2.pop();
            ans=min(ans,left[i-n]-sum2);
        }
        return ans;
    }
};
