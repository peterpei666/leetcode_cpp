#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string removeKdigits(const string& num, int k)
    {
        if(num.size()==k)
        {
            return "0";
        }
        stack<char> stk;
        for(char c:num)
        {
            while(k&&!stk.empty()&&stk.top()>c)
            {
                k--;
                stk.pop();
            }
            stk.push(c);
        }
        while(k)
        {
            k--;
            stk.pop();
        }
        string ret;
        while(!stk.empty())
        {
            ret+=stk.top();
            stk.pop();
        }
        while(!ret.empty()&&ret.back()=='0')
        {
            ret.pop_back();
        }
        if(ret.empty())
        {
            return "0";
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
