#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    char v[5]={'a','e','i','o','u'};
    
    inline int vowel(char c)
    {
        for(int i=0;i<5;i++)
        {
            if(v[i]==c)
            {
                return i;
            }
        }
        return -1;
    }
    
public:
    int findTheLongestSubstring(const string& s)
    {
        int list[1<<5];
        list[0]=-1;
        for(int i=1;i<(1<<5);i++)
        {
            list[i]=-2;
        }
        int mask=0;
        int n=(int)s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int temp=vowel(s[i]);
            if(temp==-1)
            {
                ans=max(ans,i-list[mask]);
                continue;
            }
            mask^=1<<temp;
            if(list[mask]==-2)
            {
                list[mask]=i;
            }
            else
            {
                ans=max(ans,i-list[mask]);
            }
        }
        return ans;
    }
};
