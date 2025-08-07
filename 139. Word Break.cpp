#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <bitset>
using namespace std;

class Solution
{
public:
    bool wordBreak(const string& s, vector<string>& wordDict)
    {
        unordered_set<string> mp(wordDict.begin(),wordDict.end());
        int n=(int)s.size();
        bitset<300> memo;
        bitset<300> valid;
        
        function<bool(int)> dfs=[&](int i) -> bool
        {
            if(valid.test(i))
            {
                return memo.test(i);
            }
            if(i==n)
            {
                return true;
            }
            valid.set(i);
            for(int j=i+1;j<=n;j++)
            {
                if(mp.count(s.substr(i,j-i))&&dfs(j))
                {
                    memo.set(i);
                    return true;
                }
            }
            return false;
        };
        
        return dfs(0);
    }
};
