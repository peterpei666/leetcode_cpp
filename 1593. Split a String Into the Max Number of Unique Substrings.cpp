#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int maxUniqueSplit(string s)
    {
        unordered_set<string> found;
        return dfs(s,0,(int)s.size(),found);
    }
    
    int dfs(string& s,int start,int len,unordered_set<string>& found)
    {
        int maxi=0;
        for(int i=start+1;i<=len;i++)
        {
            string sub=s.substr(start,i-start);
            if(found.find(sub)==found.end())
            {
                found.insert(sub);
                maxi=max(maxi,1+dfs(s,i,len,found));
                found.erase(sub);
            }
        }
        return maxi;
    }
};
