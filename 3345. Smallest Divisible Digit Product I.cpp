#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    static inline bool valid(int n,int t)
    {
        int pro=1;
        while(n)
        {
            pro*=n%10;
            n/=10;
        }
        return pro%t==0?true:false;
    }

public:
    int smallestNumber(int n,int t)
    {
        while(valid(n,t)==false)
        {
            n++;
        }
        return n;
    }
};
