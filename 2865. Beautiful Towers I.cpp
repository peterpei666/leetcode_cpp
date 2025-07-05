#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Solution
{
public:
    long long maximumSumOfHeights(vector<int>& maxHeights)
    {
        int n=(int)maxHeights.size();
        vector<long long> prefix(n);
        vector<long long> suffix(n);
        
        auto process=[&](vector<int>& a,vector<long long>& f)
        {
            stack<int> stk;
            stk.push(-1);
            long long sum=0;
            for(int i=0;i<n;i++)
            {
                while(stk.size()>1&&a[stk.top()]>a[i])
                {
                    int t=stk.top();
                    stk.pop();
                    sum-=1LL*(t-stk.top())*a[t];
                }
                sum+=1LL*(i-stk.top())*a[i];
                stk.push(i);
                f[i]=sum;
            }
        };
        
        process(maxHeights,prefix);
        reverse(maxHeights.begin(),maxHeights.end());
        process(maxHeights,suffix);
        reverse(suffix.begin(),suffix.end());
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,prefix[i]+suffix[i]-maxHeights[n-1-i]);
        }
        return ans;
    }
};
