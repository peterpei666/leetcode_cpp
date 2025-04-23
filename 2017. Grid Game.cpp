#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long gridGame(vector<vector<int>>& grid)
    {
        long long sum1=0;
        for(int i=1;i<grid[0].size();i++)
        {
            sum1+=grid[0][i];
        }
        long long ret=sum1,sum2=0;
        for(int i=1;i<grid[0].size();i++)
        {
            sum2+=grid[1][i-1];
            sum1-=grid[0][i];
            ret=min(ret,max(sum1,sum2));
        }
        return ret;
    }
};
