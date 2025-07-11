#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int mostBooked(int n, vector<vector<int>>& meetings)
    {
        sort(meetings.begin(),meetings.end());
        long long time[n];
        int cnt[n];
        memset(time,0,sizeof(time));
        memset(cnt,0,sizeof(cnt));
        for(auto& meeting:meetings)
        {
            int l=meeting[0];
            int r=meeting[1];
            long long mintime=1e10;
            int minp=-1;
            for(int i=0;i<n;i++)
            {
                if(time[i]<=l)
                {
                    cnt[i]++;
                    time[i]=r;
                    minp=-1;
                    break;
                }
                else if(time[i]<mintime)
                {
                    mintime=time[i];
                    minp=i;
                }
            }
            if(minp!=-1)
            {
                cnt[minp]++;
                time[minp]+=r-l;
            }
        }
        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(cnt[i]>cnt[ans])
            {
                ans=i;
            }
        }
        return ans;
    }
};
