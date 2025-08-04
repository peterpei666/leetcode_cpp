#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numDistinct(const string& s,const string& t)
    {
        int m=(int)s.size();
        int n=(int)t.size();
        int memo[m][n];
        memset(memo,-1,sizeof(memo));
        
        function<int(int,int)> dfs=[&](int i,int j) -> int
        {
            if(j==n)
            {
                return 1;
            }
            if(m-i<n-j)
            {
                return 0;
            }
            if(memo[i][j]!=-1)
            {
                return memo[i][j];
            }
            if(s[i]==t[j])
            {
                return memo[i][j]=dfs(i+1,j+1)+dfs(i+1,j);
            }
            return memo[i][j]=dfs(i+1,j);
        };
        
        return dfs(0,0);
    }
};
