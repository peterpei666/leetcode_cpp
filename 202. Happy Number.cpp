#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int next(int n)
    {
        int sum=0;
        while(n)
        {
            sum+=(n%10)*(n%10);
            n/=10;
        }
        return sum;
    }
    
    bool isHappy(int n)
    {
        unordered_set<int> mp;
        while(1)
        {
            n=next(n);
            if(n==1)
            {
                return true;
            }
            if(mp.find(n)!=mp.end())
            {
                return false;
            }
            mp.insert(n);
        }
    }
};
