#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++)
        {
            graph[i].push_back(i);
        }
        for(auto& e:edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        unordered_map<string,int> mp;
        for(auto& list:graph)
        {
            sort(list.begin(),list.end());
            string temp;
            for(int i:list)
            {
                temp+=to_string(i)+',';
            }
            mp[temp]++;
        }
        int ans=0;
        for(auto& [s,n]:mp)
        {
            if(count(s.begin(),s.end(),',')==n)
            {
                ans++;
            }
        }
        return ans;
    }
};
