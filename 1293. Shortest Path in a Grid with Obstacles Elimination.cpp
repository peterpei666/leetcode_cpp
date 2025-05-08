#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    struct point
    {
        int x;
        int y;
        int t;
        int r;
    };
    
    int shortestPath(vector<vector<int>>& grid, int k)
    {
        int m,n,ret=1000000;
        m=(int)grid.size();
        n=(int)grid[0].size();
        int d[40][40];
        int dir[4][2]={-1,0,0,-1,0,1,1,0};
        fill(&d[0][0],&d[0][0]+40*40,-1);
        d[0][0]=k;
        queue<point> q;
        q.push({0,0,0,k});
        while(!q.empty())
        {
            auto [x,y,t,r]=q.front();
            q.pop();
            if(x==m-1&&y==n-1)
            {
                return ret;
            }
            for(int i=0;i<4;i++)
            {
                int nx=x+dir[i][0];
                int ny=y+dir[i][1];
                if(nx>=0&&nx<m&&ny>=0&&ny<n)
                {
                    int nr=r;
                    if(grid[nx][ny])
                    {
                        nr--;
                    }
                    if(nr>=0&&(d[nx][ny]==-1||nr>d[nx][ny]))
                    {
                        d[nx][ny]=nr;
                        q.push({nx,ny,t+1,nr});
                    }
                }
            }
        }
        return ret==1000000?-1:ret;
    }
};
