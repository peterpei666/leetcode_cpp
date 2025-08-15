#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<string> removeInvalidParentheses(const string& s)
    {
        int l=0,r=0;
        for(char c:s)
        {
            if(c=='(')
            {
                l++;
            }
            else if(c==')')
            {
                if(l>0)
                {
                    l--;
                }
                else
                {
                    r++;
                }
            }
        }
        unordered_set<string> ans;
        string temp;
        int n=(int)s.size();
        
        function<void(int,int,int,int)> dfs=[&](int idx,int l,int r,int open)
        {
            if(idx==n)
            {
                if(l==0&&r==0&&open==0)
                {
                    ans.insert(temp);
                }
                return;
            }
            int m=(int)temp.size();
            switch(s[idx])
            {
                case '(':
                    if(l>0)
                    {
                        dfs(idx+1,l-1,r,open);
                    }
                    temp+=s[idx];
                    dfs(idx+1,l,r,open+1);
                    temp.resize(m);
                    break;
                case ')':
                    if(r>0)
                    {
                        dfs(idx+1,l,r-1,open);
                    }
                    if(open>0)
                    {
                        temp+=s[idx];
                        dfs(idx+1,l,r,open-1);
                        temp.resize(m);
                    }
                    break;
                default:
                    temp+=s[idx];
                    dfs(idx+1,l,r,open);
                    temp.resize(m);
                    break;
            }
        };
        
        dfs(0,l,r,0);
        return vector<string>(ans.begin(),ans.end());
    }
};
