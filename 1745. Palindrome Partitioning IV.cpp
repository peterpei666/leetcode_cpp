#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    bool checkPartitioning(const string& s)
    {
        int n=(int)s.size();
        bitset<2000> valid[3];
        bitset<2000> memo[3];
        bitset<2000> pal[n];
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(s[i]==s[j]&&(j-i<2||pal[i+1][j-1]))
                {
                    pal[i].set(j);
                }
            }
        }
        
        function<bool(int,int)> dfs=[&](int i,int k) -> bool
        {
            if(valid[k-1].test(i))
            {
                return memo[k-1].test(i);
            }
            if(n-i==k)
            {
                return true;
            }
            valid[k-1].set(i);
            if(k==1)
            {
                return memo[k-1][i]=pal[i].test(n-1);
            }
            for(int j=i+1;j<n-k+2;j++)
            {
                if(pal[i].test(j-1)&&dfs(j,k-1))
                {
                    return memo[k-1][i]=true;
                }
            }
            return memo[k-1][i]=false;
        };
        
        return dfs(0,3);
    }
};
