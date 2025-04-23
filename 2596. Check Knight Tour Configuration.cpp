#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    bool checkValidGrid(vector<vector<int>>& grid)
    {
        if(grid[0][0])
        {
            return false;
        }
        unsigned char arr[49];
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {
                arr[grid[i][j]]=i*7+j;
            }
        }
        for(int i=1;i<grid.size()*grid.size();i++)
        {
            if(abs(arr[i]%7-arr[i-1]%7)*abs(arr[i]/7-arr[i-1]/7)!=2)
            {
                return false;
            }
        }
        return true;
    }
};

