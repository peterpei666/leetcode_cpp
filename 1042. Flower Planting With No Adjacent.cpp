#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths)
    {
        int c[n];
        int path[n][3];
        memset(c,0,sizeof(c));
        memset(path,-1,sizeof(path));
        for(auto& p:paths)
        {
            path[p[0]-1][c[p[0]-1]]=p[1]-1;
            path[p[1]-1][c[p[1]-1]]=p[0]-1;
            c[p[0]-1]++;
            c[p[1]-1]++;
        }
        vector<int> ret(n);
        for(int i=0;i<n;i++)
        {
            int mask=0;
            for(int j=0;j<3;j++)
            {
                if(path[i][j]!=-1&&path[i][j]<i)
                {
                    mask|=1<<ret[path[i][j]];
                }
            }
            for(int j=1;j<=4;j++)
            {
                if((mask&(1<<j))==0)
                {
                    ret[i]=j;
                    break;
                }
            }
        }
        return ret;
    }
};
