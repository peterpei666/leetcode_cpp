#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k)
    {
        for(auto& r:grid)
        {
            sort(r.begin(),r.end(),greater<int>());
        }
        int n=0;
        for(int i:limits)
        {
            n+=i;
        }
        int list[n+1];
        for(int i=0,k=0;i<grid.size();i++)
        {
            for(int j=0;j<limits[i];j++)
            {
                list[k]=grid[i][j];
                k++;
            }
        }
        sort(&list[0],&list[0]+n,greater<int>());
        long long ans=0;
        for(int i=0;i<k;i++)
        {
            ans+=list[i];
        }
        return ans;
    }
};
