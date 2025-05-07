#include <iostream>
#include <algorithm>
#include <queue>
#include <bitset>
using namespace std;

class Solution
{
public:
    struct point
    {
        int x;
        int y;
        int t;
        bool operator<(const point& other) const
        {
            return t>other.t;
        }
    };
    
    int minTimeToReach(vector<vector<int>>& moveTime)
    {
        int m,n;
        const int INF=2e9;
        m=(int)moveTime.size();
        n=(int)moveTime[0].size();
        bitset<50> visited[m];
        int d[50][50];
        int dir[4][2]={-1,0,0,-1,0,1,1,0};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                d[i][j]=INF;
            }
        }
        d[0][0]=0;
        priority_queue<point> pq;
        pq.push({0,0,0});
        while(!pq.empty())
        {
            point p=pq.top();
            pq.pop();
            if(visited[p.x].test(p.y))
            {
                continue;
            }
            visited[p.x].set(p.y);
            for(int i=0;i<4;i++)
            {
                int nx=p.x+dir[i][0];
                int ny=p.y+dir[i][1];
                if(nx>=0&&nx<m&&ny>=0&&ny<n)
                {
                    int dist=max(d[p.x][p.y],moveTime[nx][ny])+1;
                    if(dist<d[nx][ny])
                    {
                        d[nx][ny]=dist;
                        pq.push({nx,ny,dist});
                    }
                }
            }
        }
        return d[m-1][n-1];
    }
};
