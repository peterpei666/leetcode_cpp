#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int i,j;
        int list[m][n];
        for(i=0;i<m;i++)
        {
            list[i][0]=1;
        }
        for(i=1;i<n;i++)
        {
            list[0][i]=1;
        }
        for(i=1;i<m;i++)
        {
            for(j=1;j<n;j++)
            {
                list[i][j]=list[i-1][j]+list[i][j-1];
            }
        }
        return list[m-1][n-1];
    }
};
