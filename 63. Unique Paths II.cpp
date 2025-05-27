#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m=(int)obstacleGrid.size();
        int n=(int)obstacleGrid[0].size();
        if(obstacleGrid[0][0]||obstacleGrid[m-1][n-1])
        {
            return 0;
        }
        obstacleGrid[0][0]=1;
        for(int i=1;i<m;i++)
        {
            if(obstacleGrid[i][0])
            {
                obstacleGrid[i][0]=0;
            }
            else
            {
                obstacleGrid[i][0]=obstacleGrid[i-1][0];
            }
        }
        for(int i=1;i<n;i++)
        {
            if(obstacleGrid[0][i])
            {
                obstacleGrid[0][i]=0;
            }
            else
            {
                obstacleGrid[0][i]=obstacleGrid[0][i-1];
            }
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j])
                {
                    obstacleGrid[i][j]=0;
                }
                else
                {
                    obstacleGrid[i][j]=obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
                }
            }
        }
        return obstacleGrid[m-1][n-1];
    }
};
