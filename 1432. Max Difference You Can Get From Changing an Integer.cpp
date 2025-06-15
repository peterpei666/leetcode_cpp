#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxDiff(int num)
    {
        int temp=num;
        int list[10]={0};
        for(int t=1;temp;t*=10)
        {
            list[temp%10]+=t;
            temp/=10;
        }
        int top=num;
        while(top>=10)
        {
            top/=10;
        }
        int m1=INT_MIN,m2=INT_MAX;
        for(int i=0;i<=9;i++)
        {
            m1=max(m1,num+(9-i)*list[i]);
            if(i==top)
            {
                m2=min(m2,num-(i-1)*list[i]);
            }
            else
            {
                m2=min(m2,num-i*list[i]);
            }
        }
        return m1-m2;
    }
};
