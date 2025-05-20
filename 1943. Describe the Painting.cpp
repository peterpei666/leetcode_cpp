#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments)
    {
        map<int,long long> list;
        for(auto& m:segments)
        {
            list[m[0]]+=m[2];
            list[m[1]]-=m[2];
        }
        vector<vector<long long>> ret;
        long long cur=0;
        int prev=-1;
        for(auto [x,n]:list)
        {
            if(prev==-1)
            {
                prev=x;
                cur+=n;
            }
            else
            {
                if(cur)
                {
                    ret.push_back({prev,x,cur});
                }
                cur+=n;
                prev=x;
            }
        }
        return ret;
    }
};
