#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c)
    {
        int m,n;
        int x=0,y=0;
        m=(int)mat.size();
        n=(int)mat[0].size();
        if(m*n!=r*c)
        {
            return mat;
        }
        vector<vector<int>> ret(r,vector<int>(c));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ret[x][y]=mat[i][j];
                y++;
                x+=y/c;
                y%=c;
            }
        }
        return ret;
    }
};
