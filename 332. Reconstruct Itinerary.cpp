#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>>& tickets)
    {
        map<string,multiset<string>> mp;
        for(auto& ticket:tickets)
        {
            mp[ticket[0]].insert(ticket[1]);
        }
        vector<string> ans;
        
        function<void(string)> dfs=[&](string p)
        {
            while(!mp[p].empty())
            {
                string next=*mp[p].begin();
                mp[p].erase(mp[p].begin());
                dfs(next);
            }
            ans.push_back(p);
        };
        
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
