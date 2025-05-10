#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        int m,n;
        m=(int)heights.size();
        n=(int)heights[0].size();
        int dir[4][2]={-1,0,0,-1,1,0,0,1};
        bitset<200> P[m],A[m];
        function<void(int,int,char)> dfs=[&](int x,int y,char a)
        {
            if(a=='P')
            {
                P[x].set(y);
                for(int i=0;i<4;i++)
                {
                    int nx=x+dir[i][0];
                    int ny=y+dir[i][1];
                    if(nx>=0&&nx<m&&ny>=0&&ny<n)
                    {
                        if(heights[nx][ny]>=heights[x][y]&&P[nx].test(ny)==false)
                        {
                            dfs(nx,ny,a);
                        }
                    }
                }
            }
            else
            {
                A[x].set(y);
                for(int i=0;i<4;i++)
                {
                    int nx=x+dir[i][0];
                    int ny=y+dir[i][1];
                    if(nx>=0&&nx<m&&ny>=0&&ny<n)
                    {
                        if(heights[nx][ny]>=heights[x][y]&&A[nx].test(ny)==false)
                        {
                            dfs(nx,ny,a);
                        }
                    }
                }
            }
        };
        for(int i=0;i<n;i++)
        {
            dfs(0,i,'P');
        }
        for(int i=0;i<m;i++)
        {
            dfs(i,0,'P');
        }
        for(int i=0;i<n;i++)
        {
            dfs(m-1,i,'A');
        }
        for(int i=0;i<m;i++)
        {
            dfs(i,n-1,'A');
        }
        vector<vector<int>> ret;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(P[i].test(j)&&A[i].test(j))
                {
                    ret.push_back({i,j});
                }
            }
        }
        return ret;
    }
};
