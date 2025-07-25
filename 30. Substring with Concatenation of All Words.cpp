#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> findSubstring(const string& s, vector<string>& words)
    {
        int wlen=(int)words[0].size();
        int wcnt=(int)words.size();
        int n=(int)s.size();
        if(n<wlen*wcnt)
        {
            return {};
        }
        unordered_map<string,int> mp;
        for(const string& w:words)
        {
            mp[w]++;
        }
        
        vector<int> ans;
        for(int i=0;i<wlen;i++)
        {
            unordered_map<string,int> temp;
            int l=i,r=i;
            int cnt=0;
            while(r+wlen<=n)
            {
                string wr=s.substr(r,wlen);
                r+=wlen;
                if(mp.count(wr))
                {
                    temp[wr]++;
                    cnt++;
                    while(temp[wr]>mp[wr])
                    {
                        string wl=s.substr(l,wlen);
                        temp[wl]--;
                        l+=wlen;
                        cnt--;
                    }
                    if(cnt==wcnt)
                    {
                        ans.push_back(l);
                    }
                }
                else
                {
                    l=r;
                    cnt=0;
                    temp.clear();
                }
            }
        }
        return ans;
    }
};
