#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumArea(vector<vector<int>>& grid)
    {
        int m=(int)grid.size();
        int n=(int)grid[0].size();
        int x1=-1,x2=-1;
        int y1=-1,y2=-1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    if(x1==-1&&y1==-1)
                    {
                        x1=i;
                        y1=j;
                    }
                    x1=min(x1,i);
                    x2=max(x2,i);
                    y1=min(y1,j);
                    y2=max(y2,j);
                }
            }
        }
        if(x1!=-1)
        {
            return (x2-x1+1)*(y2-y1+1);
        }
        return 0;
    }
};
