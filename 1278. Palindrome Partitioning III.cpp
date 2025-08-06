#include <iostream>
#include <algorithm>
using namespace std;

struct pair_hash
{
    size_t operator()(const pair<int,int>& p) const
    {
        return hash<int>()(p.first)^(hash<int>()(p.second)<<1);
    }
};

class Solution
{
    public:
    int palindromePartition(const string& s,int k)
    {
        int n=(int)s.size();
        unordered_map<pair<int,int>,int,pair_hash> memo;
        
        function<int(int,int)> cost=[&](int i,int j) -> int
        {
            int c=0;
            while(i<j)
            {
                if(s[i]!=s[j])
                {
                    c++;
                }
                i++;
                j--;
            }
            return c;
        };
        
        function<int(int,int)> dfs=[&](int i,int k) -> int
        {
            if(memo.count({i,k}))
            {
                return memo[{i,k}];
            }
            if(n-i==k)
            {
                return 0;
            }
            if(k==1)
            {
                return cost(i,n-1);
            }
            int res=INT_MAX;
            for(int j=i+1;j<n-k+2;j++)
            {
                res=min(res,dfs(j,k-1)+cost(i,j-1));
            }
            memo[{i,k}]=res;
            return res;
        };

        return dfs(0,k);
    }
};
