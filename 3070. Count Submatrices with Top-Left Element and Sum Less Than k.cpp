#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countSubmatrices(vector<vector<int>>& grid, int k)
    {
        int m=(int)grid.size();
        int n=(int)grid[0].size();
        vector<vector<long long>> mat(m,vector<long long>(n));
        mat[0][0]=grid[0][0];
        for(int i=1;i<n;i++)
        {
            mat[0][i]=mat[0][i-1]+grid[0][i];
        }
        for(int i=1;i<m;i++)
        {
            mat[i][0]=mat[i-1][0]+grid[i][0];
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                mat[i][j]=mat[i-1][j]+mat[i][j-1]+grid[i][j]-mat[i-1][j-1];
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]<=k)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
