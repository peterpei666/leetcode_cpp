#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int count(vector<vector<int>>& grid,int l,int r,int u,int d)
    {
        int x1=-1,x2=-1;
        int y1=-1,y2=-1;
        for(int i=l;i<=r;i++)
        {
            for(int j=u;j<=d;j++)
            {
                if(grid[i][j])
                {
                    if(x1==-1&&y1==-1)
                    {
                        x1=i;
                        y1=j;
                    }
                    x1=min(x1,i);
                    x2=max(x2,i);
                    y1=min(y1,j);
                    y2=max(y2,j);
                }
            }
        }
        if(x1!=-1)
        {
            return (x2-x1+1)*(y2-y1+1);
        }
        return 0;
    }
    
    int solve(vector<vector<int>>& grid)
    {
        int m=(int)grid.size();
        int n=(int)grid[0].size();
        int ans=m*n;
        for(int i=0;i<m-1;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                ans=min(ans,count(grid,0,i,0,n-1)+count(grid,i+1,m-1,0,j)+count(grid,i+1,m-1,j+1,n-1));
                ans=min(ans,count(grid,0,i,0,j)+count(grid,0,i,j+1,n-1)+count(grid,i+1,m-1,0,n-1));
            }
        }
        for(int i=0;i<m-2;i++)
        {
            for(int j=i+1;j<m-1;j++)
            {
                ans=min(ans,count(grid,0,i,0,n-1)+count(grid,i+1,j,0,n-1)+count(grid,j+1,m-1,0,n-1));
            }
        }
        return ans;
    }
    
    inline vector<vector<int>> trans(vector<vector<int>>& grid)
    {
        int m=(int)grid.size();
        int n=(int)grid[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans[j][i]=grid[i][j];
            }
        }
        return ans;
    }
    
public:
    
    int minimumSum(vector<vector<int>>& grid)
    {
        vector<vector<int>> tgrid=trans(grid);
        return min(solve(grid),solve(tgrid)); 
    }
};
