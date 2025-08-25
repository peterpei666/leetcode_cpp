#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int trapRainWater(vector<vector<int>>& heightMap)
    {
        int m=(int)heightMap.size();
        int n=(int)heightMap[0].size();
        const int dir[4][2]={-1,0,0,-1,0,1,1,0};
        using T = tuple<int,int,int>;
        auto cmp=[](const T& a,const T& b)
        {
            return get<0>(a)>get<0>(b);
        };
        priority_queue<T,vector<T>,decltype(cmp)> pq;
        bitset<200> visited[200];
        for(int i=0;i<m;i++)
        {
            pq.push({heightMap[i][0],i,0});
            pq.push({heightMap[i][n-1],i,n-1});
            visited[i].set(0);
            visited[i].set(n-1);
        }
        for(int i=1;i<n-1;i++)
        {
            pq.push({heightMap[0][i],0,i});
            pq.push({heightMap[m-1][i],m-1,i});
            visited[0].set(i);
            visited[m-1].set(i);
        }
        int ans=0;
        while(!pq.empty())
        {
            auto [h,x,y]=pq.top();
            pq.pop();
            for(int d=0;d<4;d++)
            {
                int nx=x+dir[d][0];
                int ny=y+dir[d][1];
                if(nx>=0&&nx<m&&ny>=0&&ny<n&&!visited[nx].test(ny))
                {
                    ans+=max(0,h-heightMap[nx][ny]);
                    pq.push({max(h,heightMap[nx][ny]),nx,ny});
                    visited[nx].set(ny);
                }
            }
        }
        return ans;
    }
};
