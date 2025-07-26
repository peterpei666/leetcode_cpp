#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(const string& s)
    {
        int n=(int)s.size();
        int ans=0;
        int stk[30000];
        stk[0]=-1;
        for(int i=0,j=1;i<n;i++)
        {
            if(s[i]=='(')
            {
                stk[j]=i;
                j++;
            }
            else
            {
                j--;
                if(j==0)
                {
                    stk[j]=i;
                    j++;
                }
                ans=max(ans,i-stk[j-1]);
            }
        }
        return ans;
    }
};
