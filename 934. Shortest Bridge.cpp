#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int n;
    int direction[4][2]={-1,0,0,-1,0,1,1,0};
    
    void DFS(vector<vector<int>>& grid,queue<pair<int,int>>& q,int x,int y)
    {
        if(x>=0&&x<n&&y>=0&&y<n&&grid[x][y]==1)
        {
            grid[x][y]=2;
            q.push({x,y});
            for(int d=0;d<4;d++)
            {
                DFS(grid,q,x+direction[d][0],y+direction[d][1]);
            }
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid)
    {
        n=(int)grid.size();
        queue<pair<int,int>> q;
        for(int i=0,f=1;i<n&&f;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    DFS(grid,q,i,j);
                    f=0;
                    break;
                }
            }
        }
        int s=0;
        while(!q.empty())
        {
            int size=(int)q.size();
            while(size)
            {
                size--;
                auto [x,y]=q.front();
                q.pop();
                for(int d=0;d<4;d++)
                {
                    int nx=x+direction[d][0];
                    int ny=y+direction[d][1];
                    if(nx>=0&&nx<n&&ny>=0&&ny<n)
                    {
                        if(grid[nx][ny]==1)
                        {
                            return s;
                        }
                        if(grid[nx][ny]==0)
                        {
                            grid[nx][ny]=2;
                            q.push({nx,ny});
                        }
                    }
                }
            }
            s++;
        }
        return -1;
    }
};
