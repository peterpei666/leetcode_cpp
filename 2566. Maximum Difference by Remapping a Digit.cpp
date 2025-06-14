#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minMaxDifference(int num)
    {
        int temp=num;
        int l=INT_MAX;
        int r=INT_MIN;
        int list[10]={0};
        for(int t=1;temp;t*=10)
        {
            list[temp%10]+=t;
            temp/=10;
        }
        for(int i=0;i<10;i++)
        {
            l=min(l,num-list[i]*i);
            r=max(r,num+list[i]*(9-i));
        }
        return r-l;
    }
};
