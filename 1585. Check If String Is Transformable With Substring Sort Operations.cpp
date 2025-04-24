#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isTransformable(string s, string t)
    {
        vector<vector<int>> index(10);
        vector<int> p(10);
        int len=(int)s.size();
        for(int i=0;i<len;i++)
        {
            index[s[i]-'0'].push_back(i);
        }
        for(int i=0;i<len;i++)
        {
            if(p[t[i]-'0']>=index[t[i]-'0'].size())
            {
                return false;
            }
            for(int j=0;j<t[i]-'0';j++)
            {
                if(p[j]<index[j].size()&&index[j][p[j]]<index[t[i]-'0'][p[t[i]-'0']])
                {
                    return false;
                }
            }
            p[t[i]-'0']++;
        }
        return true;
    }
};
