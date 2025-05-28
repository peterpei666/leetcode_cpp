#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lcm(int a,int b,int k)
    {
        int m1=max(a,b);
        int m2=min(a,b);
        for(int i=1;i<=m2;i++)
        {
            if(i*m1>k)
            {
                break;
            }
            if(i*m1%m2==0)
            {
                return i*m1;
            }
        }
        return k+1;
    }
    
    int subarrayLCM(vector<int>& nums, int k)
    {
        int cnt=0;
        int n=(int)nums.size();
        for(int i=0;i<n;i++)
        {
            int cur=nums[i];
            for(int j=i;j<n;j++)
            {
                cur=lcm(cur,nums[j],k);
                if(cur>k)
                {
                    break;
                }
                if(cur==k)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
