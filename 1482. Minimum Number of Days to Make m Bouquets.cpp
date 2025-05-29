#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool check(vector<int>& bloomDay,long long day,int m,int k)
    {
        int cnt=0;
        for(int d:bloomDay)
        {
            if(d<=day)
            {
                cnt++;
            }
            else
            {
                cnt=0;
            }
            if(cnt==k)
            {
                m--;
                cnt=0;
                if(m==0)
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k)
    {
        int l=0,r=0,d=-1;
        for(int i:bloomDay)
        {
            r=max(i,r);
        }
        while(l<=r)
        {
            int mid=(r+l)/2;
            if(check(bloomDay,mid,m,k))
            {
                r=mid-1;
                d=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return d;
    }
};
