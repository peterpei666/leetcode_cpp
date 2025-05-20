#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat)
    {
        vector<int> ret;
        vector<vector<int>> temp(mat.size()+mat[0].size());
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                temp[i+j].push_back(mat[i][j]);
            }
        }
        for(int i=0;i<temp.size();i++)
        {
            if(i%2==0)
            {
                reverse(temp[i].begin(),temp[i].end());
            }
            ret.insert(ret.end(),temp[i].begin(),temp[i].end());
        }
        return ret;
    }
};
