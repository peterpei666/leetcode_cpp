#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxValue(vector<vector<int>>& events, int k)
    {
        sort(events.begin(),events.end());
        int n=(int)events.size();
        vector<int> start(n);
        for(int i=0;i<n;i++)
        {
            start[i]=events[i][0];
        }
        vector<vector<int>> dp(k+1,vector<int>(n+1,0));
        for(int cur=n-1;cur>=0;cur--)
        {
            int next=(int)(upper_bound(start.begin(),start.end(),events[cur][1])-start.begin());
            for(int cnt=1;cnt<=k;cnt++)
            {
                dp[cnt][cur]=max(dp[cnt][cur+1],events[cur][2]+dp[cnt-1][next]);
            }
        }
        return dp[k][0];
    }
};
