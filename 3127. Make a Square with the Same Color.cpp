#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
	bool canMakeSquare(vector<vector<char>>& grid)
	{
		int m=(int)grid.size();
		int n=(int)grid[0].size();
		for(int i=0;i<m-1;i++)
		{
			for(int j=0;j<n-1;j++)
			{
				int B=0;
				if(grid[i][j]=='B')
				{
					B++;
				}
				if(grid[i+1][j]=='B')
				{
					B++;
				}
				if(grid[i][j+1]=='B')
				{
					B++;
				}
				if(grid[i+1][j+1]=='B')
				{
					B++;
				}
				if(B!=2)
				{
					return true;
				}
			}
		}
		return false;
	}
};
