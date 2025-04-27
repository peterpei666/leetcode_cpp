#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    bool can(int n,vector<int>& candies,long long k)
    {
        for(int i:candies)
        {
            k-=i/n;
            if(k<=0)
            {
                return true;
            }
        }
        return false;
    }
    
public:
    int maximumCandies(vector<int>& candies, long long k)
    {
        int left=0,right=0;
        for(int i:candies)
        {
            right=max(right,i);
        }
        while(left<right)
        {
            int mid=left+(-left+right+1)/2;
            if(can(mid,candies,k))
            {
                left=mid;
            }
            else
            {
                right=mid-1;
            }
        }
        return left;
    }
};
