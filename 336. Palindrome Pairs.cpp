#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
private:
    static inline bool is_pal(const string& s)
    {
        for(int l=0,r=(int)s.size()-1;l<r;l++,r--) if(s[l]!=s[r]) return false;
        return true;
    }
    
public:
    vector<vector<int>> palindromePairs(vector<string>& words)
    {
        unordered_map<string,int> mp;
        int n=(int)words.size();
        for(int i=0;i<n;i++)
        {
            string temp=words[i];
            reverse(temp.begin(),temp.end());
            mp[temp]=i;
        }
        vector<vector<int>> ans;
        if(mp.count(""))
        {
            int temp=mp[""];
            for(int i=0;i<n;i++)
            {
                if(temp==i)
                {
                    continue;
                }
                if(is_pal(words[i]))
                {
                    ans.push_back({i,temp});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            string left="";
            string right=words[i];
            int m=(int)words[i].size();
            for(int j=0;j<m;j++)
            {
                left.push_back(words[i][j]);
                right.erase(0,1);
                if(mp.count(left)&&mp[left]!=i&&is_pal(right))
                {
                    ans.push_back({i,mp[left]});
                }
                if(mp.count(right)&&mp[right]!=i&&is_pal(left))
                {
                    ans.push_back({mp[right],i});
                }
            }
        }
        return ans;
    }
};
