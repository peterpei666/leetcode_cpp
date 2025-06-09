#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int count(int n,long long pre1,long long pre2)
    {
        int step=0;
        while(pre1<=n)
        {
            step+=min((long long)n+1,pre2)-pre1;
            pre1*=10;
            pre2*=10;
        }
        return step;
    }
    
public:
    int findKthNumber(int n, int k)
    {
        int cur=1;
        k--;
        while(k)
        {
            int step=count(n,cur,cur+1);
            if(step<=k)
            {
                k-=step;
                cur++;
            }
            else
            {
                cur*=10;
                k--;
            }
        }
        return cur;
    }
};
