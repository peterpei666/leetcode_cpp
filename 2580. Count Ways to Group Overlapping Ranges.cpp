#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    inline bool can_merge(vector<int>& a,vector<int>& b)
    {
        if(a[0]>b[1]||b[0]>a[1])
        {
            return false;
        }
        return true;
    }
    
    inline void merge(vector<int>& a,vector<int>& b)
    {
        a={min(a[0],b[0]),max(a[1],b[1])};
    }
    
    int qpow(int a)
    {
        const int mod=1e9+7;
        long long ans=1,temp=2;
        while(a)
        {
            if(a&1)
            {
                ans=ans*temp%mod;
            }
            temp=temp*temp%mod;
            a>>=1;
        }
        return ans%mod;
    }
    
public:
    int countWays(vector<vector<int>>& ranges)
    {
        sort(ranges.begin(),ranges.end());
        vector<int> temp;
        int i=0,j;
        int cnt=0;
        while(i<ranges.size())
        {
            temp=ranges[i];
            i++;
            while(i<ranges.size()&&can_merge(temp,ranges[i]))
            {
                merge(temp,ranges[i]);
                i++;
            }
            cnt++;
        }
        return qpow(cnt);
    }
};
