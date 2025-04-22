#include <iostream>
#include <algorithm>
using namespace std;

const int MOD=1e9+7;
const int MAX_N=1e4+10;
const int MAX_P=15;

int c[MAX_N+MAX_P][MAX_P+1];
vector<int> ps[MAX_N];
int sieve[MAX_N];

class Solution
{
public:
    Solution(void)
    {
        if(c[0][0])
        {
            return;
        }
        for(int i=2;i<MAX_N;i++)
        {
            if(sieve[i]==0)
            {
                for(int j=i;j<MAX_N;j+=i)
                {
                    sieve[j]=i;
                }
            }
        }
        for(int i=2;i<MAX_N;i++)
        {
            int x=i;
            while(x>1)
            {
                int p=sieve[x];
                int count=0;
                while(x%p==0)
                {
                    x/=p;
                    count++;
                }
                ps[i].push_back(count);
            }
        }
        c[0][0]=1;
        for(int i=1;i<MAX_N+MAX_P;i++)
        {
            c[i][0]=1;
            for(int j=1;j<=min(i,MAX_P);j++)
            {
                c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
            }
        }
    }
    
    int idealArrays(int n, int maxValue)
    {
        long long ans=0;
        for(int x=1;x<=maxValue;x++)
        {
            long long mul=1;
            for(int p:ps[x])
            {
                mul=mul*c[n+p-1][p]%MOD;
            }
            ans=(ans+mul)%MOD;
        }
        return (int)(ans%MOD);
    }
};
