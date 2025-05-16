#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int beauty(int list[26])
    {
        int m1=0,m2=INT_MAX;
        for(int i=0;i<26;i++)
        {
            if(list[i])
            {
                m1=max(list[i],m1);
                m2=min(list[i],m2);
            }
        }
        return m1-m2;
    }
    
    int beautySum(string s)
    {
        int ans=0;
        int n=(int)s.size();
        for(int i=0;i<n;i++)
        {
            int c=0;
            int list[26]={0};
            for(int j=i;j<n;j++)
            {
                if(list[s[j]-'a']==0)
                {
                    c++;
                }
                list[s[j]-'a']++;
                if(c>=2)
                {
                    ans+=beauty(list);
                }
            }
        }
        return ans;
    }
};
