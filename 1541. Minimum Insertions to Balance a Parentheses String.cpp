#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minInsertions(const string& s)
    {
        int ans=0,cnt=0;
        int n=(int)s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                cnt++;
            }
            else
            {
                if(i+1<n&&s[i+1]==')')
                {
                    if(cnt>0)
                    {
                        cnt--;
                    }
                    else
                    {
                        ans++;
                    }
                    i++;
                }
                else
                {
                    ans++;
                    if(cnt>0)
                    {
                        cnt--;
                    }
                    else
                    {
                        ans++;
                    }
                }
            }
        }
        return ans+2*cnt;
    }
};
