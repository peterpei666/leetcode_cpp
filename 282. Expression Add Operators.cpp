#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> addOperators(const string& num,int target)
    {
        vector<string> ans;
        int n=(int)num.size();
        string s;
        
        function<void(int,long long,long long,long long)> dfs=[&](int idx,long long pre,long long cur,long long val)
        {
            if(idx==n)
            {
                if(val==target&&cur==0)
                {
                    ans.push_back(s);
                }
                return;
            }
            cur=cur*10+num[idx]-'0';
            string s1=to_string(cur);
            int m=(int)s.size();
            if(cur>0)
            {
                dfs(idx+1,pre,cur,val);
            }
            s+="+"+s1;
            dfs(idx+1,cur,0,val+cur);
            s.resize(m);
            s+="-"+s1;
            dfs(idx+1,-cur,0,val-cur);
            s.resize(m);
            s+="*"+s1;
            dfs(idx+1,pre*cur,0,val-pre+pre*cur);
            s.resize(m);
        };
        
        for(int i=1;i<=n;i++)
        {
            string begin=num.substr(0,i);
            if(i>1&&begin[0]=='0')
            {
                break;
            }
            long long m=stoll(begin);
            s=begin;
            dfs(i,m,0,m);
        }
        return ans;
    }
};
