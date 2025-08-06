#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
private:
    bitset<2001> pal[2001];
    bitset<2001> visited[2001];
    
    inline bool palindrome(const string& s,int i,int j)
    {
        if(i>=j) return true;
        if(visited[i].test(j)) return pal[i].test(j);
        visited[i].set(j);
        if(s[i]==s[j]) return pal[i][j]=palindrome(s,i+1,j-1);
        return pal[i][j]=false;
    }
    
public:
    int minCut(const string& s)
    {
        int n=(int)s.size();
        for(int i=0;i<=n;i++)
        {
            pal[i].reset();
            visited[i].reset();
        }
        int t[n+1][n+1];
        memset(t,-1,sizeof(t));
        
        function<int(int,int)> dfs=[&](int i,int j) -> int
        {
            if(i>=j||palindrome(s,i,j))
            {
                return 0;
            }
            if(t[i][j]!=-1)
            {
                return t[i][j];
            }
            int res=INT_MAX;
            for(int k=i;k<j;k++)
            {
                if(palindrome(s,i,k))
                {
                    int r=(t[k+1][j]!=-1)?t[k+1][j]:(t[k+1][j]=dfs(k+1,j));
                    res=min(res,r+1);
                }
            }
            return t[i][j]=res;
        };
        
        return dfs(0,n-1);
    }
};
