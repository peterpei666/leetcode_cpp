#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumSwap(const string& s1,const string& s2)
    {
        if(s1.size()!=s2.size())
        {
            return -1;
        }
        int n=(int)s1.size();
        int cnt[2]={0};
        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s2[i])
            {
                cnt[s1[i]-'x']++;
            }
        }
        if(cnt[0]%2!=cnt[1]%2)
        {
            return -1;
        }
        return (cnt[0]+1)/2+(cnt[1]+1)/2;
    }
};
