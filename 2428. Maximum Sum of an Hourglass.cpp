#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxSum(vector<vector<int>>& grid)
    {
        int sum=0,cur=0;
        uint8_t m=(uint8_t)grid.size(),n=(uint8_t)grid[0].size();
        for(uint8_t i=1;i<m-1;i++)
        {
            sum=grid[i-1][0]+grid[i-1][1]+grid[i-1][2]+grid[i][1]+grid[i+1][0]+grid[i+1][1]+grid[i+1][2];
            cur=max(sum,cur);
            for(uint8_t j=2;j<n-1;j++)
            {
                sum+=-grid[i-1][j-2]-grid[i+1][j-2]-grid[i][j-1]+grid[i-1][j+1]+grid[i+1][j+1]+grid[i][j];
                cur=max(sum,cur);
            }
        }
        return cur;
    }
};

