#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> countOfPairs(int n, int x, int y)
    {
        vector<int> ret(n,0);
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int temp=j-i;
                temp=min(temp,abs(x-i)+abs(y-j)+1);
                temp=min(temp,abs(x-j)+abs(y-i)+1);
                ret[temp-1]++;
            }
        }
        for(int i=0;i<n;i++)
        {
            ret[i]*=2;
        }
        return ret;
    }
};
