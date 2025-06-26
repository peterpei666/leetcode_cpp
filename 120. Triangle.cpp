#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        queue<pair<int,int>> q;
        int memo[200][200];
        memset(memo,0x7f,sizeof(memo));
        int n=(int)triangle.size();
        memo[0][0]=triangle[0][0];
        q.push({0,0});
        while(!q.empty())
        {
            auto [r,c]=q.front();
            q.pop();
            if(r+1==n)
            {
                continue;
            }
            if(memo[r+1][c]>memo[r][c]+triangle[r+1][c])
            {
                memo[r+1][c]=memo[r][c]+triangle[r+1][c];
                q.push({r+1,c});
            }
            if(memo[r+1][c+1]>memo[r][c]+triangle[r+1][c+1])
            {
                memo[r+1][c+1]=memo[r][c]+triangle[r+1][c+1];
                q.push({r+1,c+1});
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            ans=min(ans,memo[n-1][i]);
        }
        return ans;
    }
};
