#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool checkInclusion(const string& s1,const string& s2)
    {
        int l1=(int)s1.size();
        int l2=(int)s2.size();
        if(l2<l1)
        {
            return false;
        }
        int cnt1[26]={0};
        for(int i=0;i<l1;i++)
        {
            cnt1[s1[i]-'a']++;
        }
        int cnt2[26]={0};
        for(int i=0;i<l1;i++)
        {
            cnt2[s2[i]-'a']++;
        }
        for(int i=l1;i<l2;i++)
        {
            if(memcmp(cnt1,cnt2,sizeof(cnt1))==0)
            {
                return true;
            }
            cnt2[s2[i]-'a']++;
            cnt2[s2[i-l1]-'a']--;
        }
        if(memcmp(cnt1,cnt2,sizeof(cnt1))==0)
        {
            return true;
        }
        return false;
    }
};
