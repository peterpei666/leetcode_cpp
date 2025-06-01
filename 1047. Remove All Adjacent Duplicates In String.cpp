#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Solution
{
public:
    string removeDuplicates(const string& s)
    {
        stack<pair<char,int>> list;
        for(char c:s)
        {
            if(list.empty()||list.top().first!=c)
            {
                list.push({c,1});
            }
            else
            {
                auto& [_,n]=list.top();
                n++;
                if(n==2)
                {
                    list.pop();
                }
            }
        }
        string ret="";
        while(!list.empty())
        {
            auto [c,n]=list.top();
            ret+=string(n,c);
            list.pop();
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
