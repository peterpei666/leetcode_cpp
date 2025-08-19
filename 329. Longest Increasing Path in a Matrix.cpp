#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        int m=(int)matrix.size();
        int n=(int)matrix[0].size();
        int memo[m][n];
        const int dir[4][2]={-1,0,0,-1,0,1,1,0};
        memset(memo,0,sizeof(memo));
        
        function<int(int,int)> dfs=[&](int i,int j) -> int
        {
            if(memo[i][j]) return memo[i][j];
            memo[i][j]=1;
            for(int d=0;d<4;d++)
            {
                int x=i+dir[d][0];
                int y=j+dir[d][1];
                if(x>=0&&x<m&&y>=0&&y<n&&matrix[i][j]<matrix[x][y])
                {
                    memo[i][j]=max(memo[i][j],dfs(x,y)+1);
                }
            }
            return memo[i][j];
        };
        
        int ans=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans=max(ans,dfs(i,j));
            }
        }
        return ans;
    }
};
