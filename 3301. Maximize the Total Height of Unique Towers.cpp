#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    inline long long mini(long long a,long long b)
    {
        return a>b?b:a;
    }
    
    long long maximumTotalSum(vector<int>& maximumHeight)
    {
        sort(maximumHeight.begin(),maximumHeight.end());
        long long sum=0,prev;
        sum+=(long long)maximumHeight[maximumHeight.size()-1];
        prev=sum;
        for(int i=(int)maximumHeight.size()-2;i>=0;i--)
        {
            prev=mini(prev-1,(long long)maximumHeight[i]);
            sum+=prev;
        }
        if(prev<=0)
        {
            return -1;
        }
        return sum;
    }
};
