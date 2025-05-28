#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int countPairs(vector<int>& deliciousness)
    {
        const int mod=1e9+7;
        unordered_map<int,int> list;
        for(int i:deliciousness)
        {
            list[i]++;
        }
        int sum[22];
        sum[0]=1;
        for(int i=1;i<22;i++)
        {
            sum[i]=sum[i-1]*2;
        }
        long long cnt=0;
        for(auto [x,n]:list)
        {
            for(int i=0;i<22;i++)
            {
                if(sum[i]<2*x)
                {
                    continue;
                }
                if(sum[i]==2*x)
                {
                    cnt+=(long long)n*(n-1)/2;
                    cnt%=mod;
                }
                else
                {
                    if(list.count(sum[i]-x))
                    {
                        cnt+=(long long)n*list[sum[i]-x];
                        cnt%=mod;
                    }
                }
            }
        }
        return (int)cnt;
    }
};
