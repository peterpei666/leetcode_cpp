#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool canPartitionGrid(vector<vector<int>>& grid)
    {
        int m=(int)grid.size();
        int n=(int)grid[0].size();
        long long row[m];
        long long col[n];
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                row[i]+=grid[i][j];
                col[j]+=grid[i][j];
            }
        }
        long long sum=0;
        for(int i=0;i<m;i++)
        {
            sum+=row[i];
        }
        if(sum%2)
        {
            return false;
        }
        long long temp;
        temp=0;
        for(int i=0;i<m-1;i++)
        {
            temp+=row[i];
            if(temp==sum/2)
            {
                return true;
            }
        }
        temp=0;
        for(int i=0;i<n-1;i++)
        {
            temp+=col[i];
            if(temp==sum/2)
            {
                return true;
            }
        }
        return false;
    }
};
