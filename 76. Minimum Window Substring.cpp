#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    static inline bool valid(unordered_map<char,pair<int,int>>& mp)
    {
        for(auto& [_,p]:mp)
        {
            if(p.first<p.second)
            {
                return false;
            }
        }
        return true;
    }

public:
    string minWindow(const string& s, const string& t)
    {
        int m=(int)s.size();
        int n=(int)t.size();
        unordered_map<char,pair<int,int>> mp;
        for(char c:t)
        {
            mp[c].second++;
        }
        int l=0,r=0;
        int minLen=INT_MAX,start=0;
        while(r<m)
        {
            if(mp.count(s[r]))
            {
                mp[s[r]].first++;
            }
            r++;
            while(valid(mp))
            {
                if(r-l<minLen)
                {
                    minLen=r-l;
                    start=l;
                }
                if(mp.count(s[l]))
                {
                    mp[s[l]].first--;
                }
                l++;
            }
        }
        return minLen==INT_MAX?"":s.substr(start,minLen);
    }
};
