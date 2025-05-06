#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid)
    {
        int m,n;
        m=(int)grid.size();
        n=(int)grid[0].size();
        vector<vector<int>> ret(m,vector<int>(n,1));
        long long pre=1,suf=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ret[i][j]*=pre;
                ret[i][j]%=12345;
                ret[m-1-i][n-1-j]*=suf;
                ret[m-1-i][n-1-j]%=12345;
                pre*=(long long)grid[i][j];
                pre%=12345;
                suf*=(long long)grid[m-1-i][n-1-j];
                suf%=12345;
            }
        }
        return ret;
    }
};
