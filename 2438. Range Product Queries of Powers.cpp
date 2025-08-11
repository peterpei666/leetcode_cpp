#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries)
    {
        int k=0,i=0;
        int bit[32]={0};
        while(n)
        {
            if(n&1)
            {
                bit[k]=1<<i;
                k++;
            }
            i++;
            n>>=1;
        }
        int p[32][32];
        const int mod=1e9+7;
        for(int i=0;i<k;i++)
        {
            p[i][i]=bit[i];
            for(int j=i+1;j<k;j++)
            {
                p[i][j]=(long long)p[i][j-1]*bit[j]%mod;
            }
        }
        int m=(int)queries.size();
        vector<int> ans(m);
        for(int i=0;i<m;i++)
        {
            ans[i]=p[queries[i][0]][queries[i][1]];
        }
        return ans;
    }
};
