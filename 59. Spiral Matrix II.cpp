#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> graph(n,vector<int>(n,0));
        int x=0,y=0;
        int dy=1,dx=0;
        int cnt=1;
        while(cnt<=n*n)
        {
            graph[x][y]=cnt;
            if(x+dx<0||x+dx>=n||y+dy<0||y+dy>=n||graph[x+dx][y+dy])
            {
                int temp=dx;
                dx=dy;
                dy=-temp;
            }
            x+=dx;
            y+=dy;
            cnt++;
        }
        return graph;
    }
};
