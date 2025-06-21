#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int valueAfterKSeconds(int n, int k)
    {
        const int mod=1e9+7;
        vector<vector<int>> list(2,vector<int>(n,1));
        for(int i=1;i<=k;i++)
        {
            list[i%2][0]=list[(i-1)%2][0];
            for(int j=1;j<n;j++)
            {
                list[i%2][j]=(list[i%2][j-1]+list[(i-1)%2][j])%mod;
            }
        }
        return list[k%2][n-1];
    }
};
