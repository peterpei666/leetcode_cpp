#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findSubstringInWraproundString(const string& s)
    {
        int list[26]={0};
        int len=1,n=(int)s.size();
        list[s[0]-'a']=1;
        for(int i=1;i<n;i++)
        {
            if((s[i]-s[i-1]+26)%26==1)
            {
                len++;
            }
            else
            {
                len=1;
            }
            list[s[i]-'a']=max(list[s[i]-'a'],len);
        }
        int ans=0;
        for(int i=0;i<26;i++)
        {
            ans+=list[i];
        }
        return ans;
    }
};
