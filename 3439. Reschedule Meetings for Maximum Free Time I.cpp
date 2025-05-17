#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime)
    {
        int n=(int)startTime.size();
        int gap[n+1];
        gap[0]=startTime[0];
        for(int i=1;i<n;i++)
        {
            gap[i]=startTime[i]-endTime[i-1];
        }
        gap[n]=eventTime-endTime[n-1];
        int prefix[n+2];
        prefix[0]=0;
        for(int i=1;i<n+2;i++)
        {
            prefix[i]=prefix[i-1]+gap[i-1];
        }
        int ans=0;
        for(int i=k+1;i<n+2;i++)
        {
            ans=max(ans,prefix[i]-prefix[i-k-1]);
        }
        return ans;
    }
};
