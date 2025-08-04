#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    static inline bool valid(const string& s1,const string& s2)
    {
        int cnt1[26]={0},cnt2[26]={0};
        for(char c:s1) cnt1[c-'a']++;
        for(char c:s2) cnt2[c-'a']++;
        return !memcmp(cnt1,cnt2,sizeof(int)*26);
    }
    
    bool func(const string& s1,const string& s2,unordered_map<string,bool>& mp)
    {
        string temp=s1+","+s2;
        if(mp.count(temp))
        {
            return mp[temp];
        }
        if(!valid(s1,s2))
        {
            mp[temp]=false;
            return mp[temp];
        }
        if(s1.size()==1)
        {
            return true;
        }
        for(int i=1;i<s1.size();i++)
        {
            if((func(s1.substr(0,i),s2.substr(s2.size()-i,i),mp)&&func(s1.substr(i,s1.size()-i),s2.substr(0,s2.size()-i),mp))||(func(s1.substr(0,i),s2.substr(0,i),mp)&&func(s1.substr(i,s1.size()-i),s2.substr(i,s2.size()-i),mp)))
            {
                mp[temp]=true;
                return true;
            }
        }
        mp[temp]=false;
        return false;
    }
    
public:
    bool isScramble(const string& s1,const string& s2)
    {
        unordered_map<string,bool> mp;
        return func(s1,s2,mp);
    }
};
