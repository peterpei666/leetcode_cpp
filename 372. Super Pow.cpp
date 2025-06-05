#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int superPow(int a, vector<int>& b)
    {
        const int mod=1337;
        a%=mod;
        int temp=a,t=a;
        int ans=1;
        int n=(int)b.size();
        for(int i=n-1;i>=0;i--)
        {
            while(b[i])
            {
                b[i]--;
                ans=(ans*temp)%mod;
            }
            for(int j=0;j<9;j++)
            {
                temp=(temp*t)%mod;
            }
            t=temp;
        }
        return ans;
    }
};
