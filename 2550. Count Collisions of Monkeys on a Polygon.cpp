#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    const int mod=1e9+7;
    
    int qpow(int n)
    {
        long long temp=2;
        long long cur=1;
        while(n)
        {
            if(n&1)
            {
                cur=cur*temp%mod;
            }
            n>>=1;
            temp=temp*temp%mod;
        }
        return cur%mod;
    }
    
public:
    int monkeyMove(int n)
    {
        return (qpow(n)-2+mod)%mod;
    }
};
