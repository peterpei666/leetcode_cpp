#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int maxDistance(vector<vector<int>>& grid)
    {
        int n=(int)grid.size();
        queue<pair<int,int>> q;
        int dir[4][2]={-1,0,0,-1,0,1,1,0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    grid[i][j]=10000;
                }
                else
                {
                    grid[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop();
            for(int d=0;d<4;d++)
            {
                int nx=x+dir[d][0];
                int ny=y+dir[d][1];
                if(nx>=0&&nx<n&&ny>=0&&ny<n&&grid[x][y]+1<grid[nx][ny])
                {
                    grid[nx][ny]=grid[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        int dis=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dis=max(dis,grid[i][j]);
            }
        }
        if(dis==0||dis==10000)
        {
            return -1;
        }
        return dis;
    }
};
