#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Solution
{
public:
    int calculate(const string& s)
    {
        int sum=0;
        int sign=1;
        stack<pair<int,int>> stk;
        int n=(int)s.size();
        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
                long long num=0;
                while(i<n&&isdigit(s[i]))
                {
                    num=num*10+(s[i]-'0');
                    i++;
                }
                i--;
                sum+=num*sign;
                sign=1;
            }
            else if(s[i]=='(')
            {
                stk.push({sum,sign});
                sum=0;
                sign=1;
            }
            else if(s[i]==')')
            {
                sum=stk.top().first+stk.top().second*sum;
                stk.pop();
            }
            else if(s[i]=='-')
            {
                sign=-sign;
            }
        }
        return sum;
    }
};
