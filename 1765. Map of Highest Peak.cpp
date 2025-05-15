#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    const int INF=1000000;
    
    int dir[4][2]={-1,0,0,-1,1,0,0,1};
    
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater)
    {
        int m=(int)isWater.size();
        int n=(int)isWater[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> height(m,vector<int>(n,INF));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isWater[i][j])
                {
                    height[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+dir[i][0];
                int ny=y+dir[i][1];
                if(nx>=0&&nx<m&&ny>=0&&ny<n&&height[nx][ny]>height[x][y]+1)
                {
                    height[nx][ny]=height[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        return height;
    }
};
