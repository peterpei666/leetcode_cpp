#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges)
    {
        vector<vector<int>> red(n);
        for(auto& e:redEdges)
        {
            red[e[0]].push_back(e[1]);
        }
        vector<vector<int>> blue(n);
        for(auto& e:blueEdges)
        {
            blue[e[0]].push_back(e[1]);
        }
        vector<int> list1(n,INT_MAX);
        vector<int> list2(n,INT_MAX);
        queue<int> q;
        list1[0]=0;
        list2[0]=0;
        q.push((0<<1)+0); //red
        q.push((0<<1)+1); //blue
        while(!q.empty())
        {
            int top=q.front();
            q.pop();
            int node=top>>1;
            int b=top&1;
            if(b)
            {
                for(int next:red[node])
                {
                    if(list1[next]>list2[node]+1)
                    {
                        list1[next]=list2[node]+1;
                        q.push(next<<1);
                    }
                }
            }
            else
            {
                for(int next:blue[node])
                {
                    if(list2[next]>list1[node]+1)
                    {
                        list2[next]=list1[node]+1;
                        q.push((next<<1)+1);
                    }
                }
            }
        }
        vector<int> ret(n);
        for(int i=0;i<n;i++)
        {
            ret[i]=min(list1[i],list2[i]);
            if(ret[i]==INT_MAX)
            {
                ret[i]=-1;
            }
        }
        return ret;
    }
};
