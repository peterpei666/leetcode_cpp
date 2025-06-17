#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long dividePlayers(vector<int>& skill)
    {
        int list[1001]={0};
        long long sum=0;
        for(int i:skill)
        {
            list[i]++;
            sum+=i;
        }
        int n=(int)skill.size()/2;
        if(sum%n)
        {
            return -1;
        }
        sum/=n;
        long long ans=0;
        for(int x=1;x<=sum/2;x++)
        {
            if(sum-x>1000)
            {
                continue;
            }
            if(sum==2*x)
            {
                if(list[x]%2)
                {
                    return -1;
                }
                ans+=(long long)x*x*list[x]/2;
                list[x]=0;
            }
            else
            {
                if(list[(int)(sum-x)]!=list[x])
                {
                    return -1;
                }
                ans+=x*(sum-x)*list[x];
                list[x]=0;
                list[sum-x]=0;
            }
        }
        return ans;
    }
};
