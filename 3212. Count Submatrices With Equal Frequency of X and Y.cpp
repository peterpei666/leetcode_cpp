#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numberOfSubmatrices(vector<vector<char>>& grid)
    {
        int m=(int)grid.size();
        int n=(int)grid[0].size();
        int x[m+1][n+1];
        int y[m+1][n+1];
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                x[i][j]=x[i-1][j]+x[i][j-1]-x[i-1][j-1];
                y[i][j]=y[i-1][j]+y[i][j-1]-y[i-1][j-1];
                if(grid[i-1][j-1]=='X')
                {
                    x[i][j]++;
                }
                if(grid[i-1][j-1]=='Y')
                {
                    y[i][j]++;
                }
            }
        }
        int cnt=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(x[i][j]==y[i][j]&&x[i][j])
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
