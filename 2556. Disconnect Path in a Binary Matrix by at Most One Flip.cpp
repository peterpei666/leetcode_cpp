#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int m,n;
    
    bool dfs(vector<vector<int>>& grid,int x,int y)
    {
        if(x==m-1&&y==n-1)
        {
            return true;
        }
        if(x>=m||y>=n||grid[x][y]==0)
        {
            return false;
        }
        grid[x][y]=0;
        return dfs(grid,x+1,y)||dfs(grid,x,y+1);
    }
    
    bool isPossibleToCutPath(vector<vector<int>>& grid)
    {
        m=(int)grid.size();
        n=(int)grid[0].size();
        if(dfs(grid,0,0)==false)
        {
            return true;
        }
        grid[0][0]=1;
        return !dfs(grid,0,0);
    }
};

