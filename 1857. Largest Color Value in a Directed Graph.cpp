#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int dfs(int node,const string& colors,vector<vector<int>>& adj,vector<vector<int>>& count,vector<int>& visit)
    {
        if(visit[node]==0)
        {
            visit[node]=1;
            for(int next:adj[node])
            {
                if(dfs(next,colors,adj,count,visit)==INT_MAX)
                {
                    return INT_MAX;
                }
                for(int c=0;c<26;c++)
                {
                    count[node][c]=max(count[node][c],count[next][c]);
                }
            }
            count[node][colors[node]-'a']++;
            visit[node]=2;
        }
        return visit[node]==2?count[node][colors[node]-'a']:INT_MAX;
    }
    
public:
    int largestPathValue(const string& colors, vector<vector<int>>& edges)
    {
        int n=(int)colors.size();
        vector<vector<int>> adj(n);
        vector<vector<int>> count(n,vector<int>(26,0));
        vector<int> visit(n,0);
        for(auto& e:edges)
        {
            adj[e[0]].push_back(e[1]);
        }
        int ans=0;
        for(int i=0;i<n&&ans!=INT_MAX;i++)
        {
            ans=max(ans,dfs(i,colors,adj,count,visit));
        }
        return ans==INT_MAX?-1:ans;
    }
};
