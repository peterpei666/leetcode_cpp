#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string makeFancyString(string s)
    {
        string ans;
        ans+=s[0];
        int n=(int)s.size();
        int cnt=1;
        for(int i=1;i<n;i++)
        {
            if(s[i]!=s[i-1])
            {
                cnt=1;
            }
            else
            {
                cnt++;
            }
            if(cnt<=2)
            {
                ans+=s[i];
            }
        }
        return ans;
    }
};
