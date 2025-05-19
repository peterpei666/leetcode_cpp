#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minSteps(string& s, string& t)
    {
        int list[26]={0};
        int l;
        l=(int)s.size();
        for(int i=0;i<l;i++)
        {
            list[s[i]-'a']++;
        }
        l=(int)t.size();
        for(int i=0;i<l;i++)
        {
            list[t[i]-'a']--;
        }
        int ret=0;
        for(int i=0;i<26;i++)
        {
            ret+=abs(list[i]);
        }
        return ret;
    }
};
