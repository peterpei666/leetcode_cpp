#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string findCommonResponse(vector<vector<string>>& responses)
    {
        unordered_map<string,pair<int,int>> list;
        int n=(int)responses.size();
        for(int i=0;i<n;i++)
        {
            for(auto& str:responses[i])
            {
                if(list[str].second!=i+1)
                {
                    list[str].first++;
                    list[str].second=i+1;
                }
            }
        }
        string ret="";
        int cnt=0;
        for(auto& [s,n]:list)
        {
            if(n.first>cnt)
            {
                ret=s;
                cnt=n.first;
            }
            else if(n.first==cnt)
            {
                if(s<ret)
                {
                    ret=s;
                }
            }
        }
        return ret;
    }
};
