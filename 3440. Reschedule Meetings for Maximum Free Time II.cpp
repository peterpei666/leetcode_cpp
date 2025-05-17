#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime)
    {
        int n=(int)startTime.size();
        int gap[n+1];
        gap[0]=startTime[0];
        for(int i=1;i<n;i++)
        {
            gap[i]=startTime[i]-endTime[i-1];
        }
        gap[n]=eventTime-endTime[n-1];
        int largest[n+1];
        largest[n]=0;
        for(int i=n-1;i>=0;i--)
        {
            largest[i]=max(largest[i+1],gap[i+1]);
        }
        int ans=0,left=0;
        for(int i=1;i<=n;i++)
        {
            int cur=endTime[i-1]-startTime[i-1];
            if(cur<=max(left,largest[i]))
            {
                ans=max(ans,gap[i-1]+gap[i]+cur);
            }
            ans=max(ans,gap[i-1]+gap[i]);
            left=max(left,gap[i-1]);
        }
        return ans;
    }
};
