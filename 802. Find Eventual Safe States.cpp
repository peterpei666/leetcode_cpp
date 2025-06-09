#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
private:
    bool dfs(bitset<10000>& visit,bitset<10000>& instack,int node,vector<vector<int>>& graph)
    {
        if(instack.test(node))
        {
            return true;
        }
        if(visit.test(node))
        {
            return false;
        }
        visit.set(node);
        instack.set(node);
        for(int next:graph[node])
        {
            if(dfs(visit,instack,next,graph))
            {
                return true;
            }
        }
        instack.reset(node);
        return false;
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        bitset<10000> visit;
        bitset<10000> instack;
        int n=(int)graph.size();
        for(int i=0;i<n;i++)
        {
            dfs(visit,instack,i,graph);
        }
        vector<int> ret;
        for(int i=0;i<n;i++)
        {
            if(instack.test(i)==false)
            {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
