#include <iostream>
#include <algorithm>
#include <queue>
#include <bitset>
using namespace std;

class Solution
{
public:
    int maximumSafenessFactor(vector<vector<int>>& grid)
    {
        queue<pair<int,int>> q;
        int n=(int)grid.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    count++;
                }
                grid[i][j]--;
            }
        }
        int direction[4][2]={-1,0,0,-1,1,0,0,1};
        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop();
            for(int d=0;d<4;d++)
            {
                int nx=x+direction[d][0];
                int ny=y+direction[d][1];
                if(nx>=0&&nx<n&&ny>=0&&ny<n&&grid[nx][ny]==-1)
                {
                    grid[nx][ny]=grid[x][y]+1;
                    q.push({nx,ny});
                    count++;
                }
            }
            if(count==n*n)
            {
                q=queue<pair<int, int>>();
                break;
            }
        }
        priority_queue<pair<int,pair<int,int>>> pq;
        bitset<160000> visited;
        pq.push({grid[0][0],{0,0}});
        visited.set(0);
        while(!pq.empty())
        {
            auto [s,p]=pq.top();
            pq.pop();
            int x=p.first,y=p.second;
            if(x==n-1&&y==n-1)
            {
                return s;
            }
            for(int d=0;d<4;d++)
            {
                int nx=x+direction[d][0];
                int ny=y+direction[d][1];
                if(nx>=0&&nx<n&&ny>=0&&ny<n&&visited.test(nx*400+ny)==false)
                {
                    pq.push({min(grid[nx][ny],s),{nx,ny}});
                    visited.set(nx*400+ny);
                }
            }
        }
        return -1;
    }
};

