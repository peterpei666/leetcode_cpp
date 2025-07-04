#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries)
    {
        vector<vector<int>> ret(n,vector<int>(n,0));
        for(auto& q:queries)
        {
            ret[q[0]][q[1]]++;
            if(q[2]+1<n)
            {
                ret[q[2]+1][q[1]]--;
            }
            if(q[3]+1<n)
            {
                ret[q[0]][q[3]+1]--;
            }
            if(q[2]+1<n&&q[3]+1<n)
            {
                ret[q[2]+1][q[3]+1]++;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                ret[i][j]=ret[i][j-1]+ret[i][j];
            }
        }
        for(int j=0;j<n;j++)
        {
            for(int i=1;i<n;i++)
            {
                ret[i][j]=ret[i][j]+ret[i-1][j];
            }
        }
        return ret;
    }
};
