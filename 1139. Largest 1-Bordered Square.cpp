#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int largest1BorderedSquare(vector<vector<int>>& grid)
    {
        int m=(int)grid.size();
        int n=(int)grid[0].size();
        int x[m][n];
        int y[m][n];
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    x[i][j]=j==0?1:x[i][j-1]+1;
                    y[i][j]=i==0?1:y[i-1][j]+1;
                }
            }
        }
        int ans=0;
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int small=min(x[i][j],y[i][j]);
                while(small>ans)
                {
                    if(x[i-small+1][j]>=small&&y[i][j-small+1]>=small)
                    {
                        ans=small;
                    }
                    small--;
                }
            }
        }
        return ans*ans;
    }
};
