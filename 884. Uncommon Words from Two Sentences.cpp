#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        unordered_map<string,int> mp;
        for(int i=0;i<s1.size();i++)
        {
            string temp="";
            while(i<s1.size()&&s1[i]!=' ')
            {
                temp+=s1[i];
                i++;
            }
            mp[temp]++;
        }
        for(int i=0;i<s2.size();i++)
        {
            string temp="";
            while(i<s2.size()&&s2[i]!=' ')
            {
                temp+=s2[i];
                i++;
            }
            mp[temp]++;
        }
        vector<string> ret;
        for(auto& [s,n]:mp)
        {
            if(n==1)
            {
                ret.push_back(s);
            }
        }
        return ret;
    }
};
