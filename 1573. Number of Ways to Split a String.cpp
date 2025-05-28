#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numWays(const string& s)
    {
        const int mod=1e9+7;
        int cnt=0;
        for(char c:s)
        {
            if(c=='1')
            {
                cnt++;
            }
        }
        int n=(int)s.size();
        if(cnt==0)
        {
            return (long long)(n-1)*(n-2)/2%mod;
        }
        if(cnt%3)
        {
            return 0;
        }
        cnt/=3;
        int n1=1,n2=1;
        for(int i=0,cnt1=0;i<n&&cnt1<=cnt;i++)
        {
            if(s[i]=='1')
            {
                cnt1++;
            }
            if(s[i]=='0'&&cnt1==cnt)
            {
                n1++;
            }
        }
        for(int i=n-1,cnt1=0;i>=0&&cnt1<=cnt;i--)
        {
            if(s[i]=='1')
            {
                cnt1++;
            }
            if(s[i]=='0'&&cnt1==cnt)
            {
                n2++;
            }
        }
        return (long long)n1*n2%mod;
    }
};
