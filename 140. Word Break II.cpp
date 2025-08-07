#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <bitset>
using namespace std;

class Solution
{
public:
    vector<string> wordBreak(const string& s,vector<string>& wordDict)
    {
        unordered_set<string> mp(wordDict.begin(),wordDict.end());
        vector<string> ans;
        string path;
        int n=(int)s.size();
        
        function<void(int)> dfs=[&](int i) -> void
        {
            if(i==n)
            {
                ans.push_back(path);
                return;
            }
            for(int j=i+1;j<=n;j++)
            {
                if(mp.count(s.substr(i,j-i)))
                {
                    int m=(int)path.size();
                    if(m)
                    {
                        path+=" ";
                    }
                    path+=s.substr(i,j-i);
                    dfs(j);
                    path=path.substr(0,m);
                }
            }
        };
        
        dfs(0);
        return ans;
    }
};
