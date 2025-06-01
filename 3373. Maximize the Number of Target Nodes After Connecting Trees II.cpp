#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    void dfs(int node,int parent,bool odd,bitset<100000>& tree,vector<vector<int>>& graph)
    {
        if(odd)
        {
            tree.set(node);
        }
        odd^=1;
        for(int next:graph[node])
        {
            if(next!=parent)
            {
                dfs(next,node,odd,tree,graph);
            }
        }
    }
    
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2)
    {
        int m;
        {
            bitset<100000> tree2;
            {
                vector<vector<int>> graph(edges2.size()+1);
                for(auto& e:edges2)
                {
                    graph[e[0]].push_back(e[1]);
                    graph[e[1]].push_back(e[0]);
                }
                dfs(0,-1,true,tree2,graph);
            }
            int temp=(int)tree2.count();
            m=max((int)temp,(int)(edges2.size()+1-temp));
        }
        bitset<100000> tree1;
        {
            vector<vector<int>> graph(edges1.size()+1);
            for(auto& e:edges1)
            {
                graph[e[0]].push_back(e[1]);
                graph[e[1]].push_back(e[0]);
            }
            dfs(0,-1,true,tree1,graph);
        }
        int n=(int)edges1.size()+1;
        int odd=(int)tree1.count();
        int even=(int)(n-odd);
        vector<int> ret(n);
        for(int i=0;i<n;i++)
        {
            if(tree1.test(i))
            {
                ret[i]=odd+m;
            }
            else
            {
                ret[i]=even+m;
            }
        }
        return ret;
    }
};
