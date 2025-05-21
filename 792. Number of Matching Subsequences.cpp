#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    unordered_map<char,vector<int>> list;
    
    bool check(string& s,unordered_map<char,vector<int>>& list)
    {
        int prev=-1;
        int idx=0;
        while(idx<s.size())
        {
            char target=s[idx];
            auto it=upper_bound(list[target].begin(),list[target].end(),prev);
            if(it==list[target].end())
            {
                return false;
            }
            prev=*it;
            idx++;
        }
        return true;
    }
    int numMatchingSubseq(const string& s, vector<string>& words)
    {
        for(int i=0;i<s.size();i++)
        {
            list[s[i]].push_back(i);
        }
        int count=0;
        for(auto& w:words)
        {
            if(check(w,list))
            {
                count++;
            }
        }
        return count;
    }
};
