#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    const int mod=1e9+7;
    
    inline long long qpow(long long a,int b)
    {
        long long ans=1;
        while(b)
        {
            if(b&1)
            {
                ans*=a;
                ans%=mod;
            }
            b>>=1;
            a=a*a%mod;
        }
        return ans;
    }
    
    inline long long factorial(int n)
    {
        long long ans=1;
        for(int i=2;i<=n;i++)
        {
            ans*=i;
            ans%=mod;
        }
        return ans;
    }
    
    long long fact[100001];
    long long invfact[100001];
    bool ready=false;
    
    void initialize(void)
    {
        fact[0]=1;
        for(int i=1;i<100001;i++)
        {
            fact[i]=fact[i-1]*i%mod;
        }
        invfact[100000]=qpow(fact[100000],mod-2);
        for(int i=99999;i>=0;i--)
        {
            invfact[i]=invfact[i+1]*(i+1)%mod;
        }
    }
    
    inline long long comb(int n,int m)
    {
        return fact[n]*invfact[m]%mod*invfact[n-m]%mod;
    }
    
public:
    int countGoodArrays(int n, int m, int k)
    {
        if(ready==false)
        {
            initialize();
            ready=true;
        }
        return comb(n-1,k)*m%mod*qpow(m-1,n-k-1)%mod;
    }
};
