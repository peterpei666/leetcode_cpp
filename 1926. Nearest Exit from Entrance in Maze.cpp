#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    struct state
    {
        int x;
        int y;
        int dis;
    };
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance)
    {
        int dir[4][2]={-1,0,0,-1,0,1,1,0};
        int m=(int)maze.size();
        int n=(int)maze[0].size();
        queue<state> q;
        q.push({entrance[0],entrance[1],0});
        maze[entrance[0]][entrance[1]]='+';
        while(!q.empty())
        {
            auto [x,y,dis]=q.front();
            q.pop();
            for(int d=0;d<4;d++)
            {
                int nx=x+dir[d][0];
                int ny=y+dir[d][1];
                if((nx<0||nx>=m||ny<0||ny>=n)&&dis)
                {
                    return dis;
                }
                if(nx>=0&&nx<m&&ny>=0&&ny<n&&maze[nx][ny]!='+')
                {
                    maze[nx][ny]='+';
                    q.push({nx,ny,dis+1});
                }
            }
        }
        return -1;
    }
};
