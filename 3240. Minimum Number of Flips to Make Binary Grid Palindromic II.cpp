#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minFlips(vector<vector<int>>& grid)
    {
        int m=(int)grid.size();
        int n=(int)grid[0].size();
        int ans=0;
        int total1=0;
        for(int i=0;i<m/2;i++)
        {
            for(int j=0;j<n/2;j++)
            {
                int one=grid[i][j]+grid[m-1-i][j]+grid[i][n-1-j]+grid[m-1-i][n-1-j];
                if(one==0||one==4)
                {
                    total1+=one;
                }
                else if(one>=2)
                {
                    ans+=4-one;
                    total1+=4;
                }
                else
                {
                    ans+=one;
                }
            }
        }
        if(m%2==0&&n%2==0)
        {
            return ans;
        }
        int palindrome1=0;
        int change=0;
        if(m%2)
        {
            for(int i=0;i<n/2;i++)
            {
                if(grid[m/2][i]&&grid[m/2][n-1-i])
                {
                    palindrome1++;
                }
                if(grid[m/2][i]!=grid[m/2][n-1-i])
                {
                    ans++;
                    change++;
                }
            }
        }
        if(n%2)
        {
            for(int i=0;i<m/2;i++)
            {
                if(grid[i][n/2]&&grid[m-1-i][n/2])
                {
                    palindrome1++;
                }
                if(grid[i][n/2]!=grid[m-1-i][n/2])
                {
                    ans++;
                    change++;
                }
            }
        }
        if(palindrome1%2&&change==0)
        {
            ans+=2;
        }
        if(m%2&&n%2&&grid[m/2][n/2])
        {
            ans++;
        }
        return ans;
    }
};
