#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    void dfs(int node,int n,vector<vector<int>>& graph,vector<int>& path,vector<vector<int>>& paths)
    {
        path.push_back(node);
        if(node==n-1)
        {
            paths.push_back(path);
            path.pop_back();
            return;
        }
        for(int next:graph[node])
        {
            dfs(next,n,graph,path,paths);
        }
        path.pop_back();
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        int n=(int)graph.size();
        vector<vector<int>> paths;
        vector<int> path;
        dfs(0,n,graph,path,paths);
        return paths;
    }
};
