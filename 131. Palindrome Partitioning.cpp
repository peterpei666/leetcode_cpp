#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    static inline bool is_palindrome(const string& s)
    {
        int l=0,r=(int)s.size()-1;
        while(l<r)
        {
            if(s[l]!=s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    
    void dfs(const string& s,int idx,vector<string>& temp)
    {
        if(idx==n)
        {
            ret.push_back(temp);
            return;
        }
        string cur="";
        for(int i=idx;i<n;i++)
        {
            cur+=s[i];
            if(is_palindrome(cur))
            {
                temp.push_back(cur);
                dfs(s,i+1,temp);
                temp.pop_back();
            }
        }
    }
    
    int n;
    vector<vector<string>> ret;
public:
    vector<vector<string>> partition(const string& s)
    {
        n=(int)s.size();
        ret.clear();
        vector<string> temp;
        dfs(s,0,temp);
        return ret;
    }
};
