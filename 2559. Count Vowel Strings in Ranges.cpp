#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    inline bool vowel(char c)
    {
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        {
            return true;
        }
        return false;
    }
    
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries)
    {
        int n=(int)words.size();
        int list[n];
        if(vowel(*words[0].begin())&&vowel(*words[0].rbegin()))
        {
            list[0]=1;
        }
        else
        {
            list[0]=0;
        }
        for(int i=1;i<n;i++)
        {
            if(vowel(*words[i].begin())&&vowel(*words[i].rbegin()))
            {
                list[i]=list[i-1]+1;
            }
            else
            {
                list[i]=list[i-1];
            }
        }
        n=(int)queries.size();
        vector<int> ret(n);
        for(int i=0;i<n;i++)
        {
            if(queries[i][0]==0)
            {
                ret[i]=list[queries[i][1]];
            }
            else
            {
                ret[i]=list[queries[i][1]]-list[queries[i][0]-1];
            }
        }
        return ret;
    }
};
