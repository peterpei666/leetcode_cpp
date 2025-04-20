#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads)
    {
        set<pair<int,int>> point_set;
        point_set.insert({start[0],start[1]});
        point_set.insert({target[0],target[1]});
        for(auto& p:specialRoads)
        {
            point_set.insert({p[0],p[1]});
            point_set.insert({p[2],p[3]});
        }
        vector<pair<int,int>> points(point_set.begin(),point_set.end());
        unordered_map<string,int> index;
        int n=(int)points.size();
        for(int i=0;i<n;i++)
        {
            index[to_string(points[i].first)+","+to_string(points[i].second)]=i;
        }
        vector<vector<pair<int,int>>> graph(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    int cost=abs(points[i].first-points[j].first)+abs(points[i].second-points[j].second);
                    graph[i].push_back({j,cost});
                }
            }
        }
        for(auto& p:specialRoads)
        {
            string a=to_string(p[0])+","+to_string(p[1]);
            string b=to_string(p[2])+","+to_string(p[3]);
            int u=index[a];
            int v=index[b];
            graph[u].push_back({v,p[4]});
        }
        vector<int> dist(n,INT_MAX);
        int st=index[to_string(start[0])+","+to_string(start[1])];
        dist[st]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,st});
        while(!pq.empty())
        {
            auto [d,u]=pq.top();
            pq.pop();
            if(d>dist[u])
            {
                continue;
            }
            for(auto& [v,cost]:graph[u])
            {
                if(dist[v]>dist[u]+cost)
                {
                    dist[v]=dist[u]+cost;
                    pq.push({dist[v],v});
                }
            }
        }
        int ed=index[to_string(target[0])+","+to_string(target[1])];
        return dist[ed];
    }
};
