#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string temp;
        
        function<void(int,int)> dfs=[&](int l,int r)
        {
            if(l==0&&r==0)
            {
                ans.push_back(temp);
                return;
            }
            if(l)
            {
                temp+="(";
                dfs(l-1,r+1);
                temp.pop_back();
            }
            if(r)
            {
                temp+=")";
                dfs(l,r-1);
                temp.pop_back();
            }
        };
        
        dfs(n,0);
        return ans;
    }
};
