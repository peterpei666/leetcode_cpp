#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        map<int,int> list;
        for(auto& q:intervals)
        {
            list[q[0]]--;
            list[q[1]]++;
        }
        vector<vector<int>> ret;
        int c=0;
        int l=-1,r=0;
        for(auto& [i,n]:list)
        {
            if(n<0)
            {
                if(c==0)
                {
                    l=i;
                }
                c+=n;
            }
            else
            {
                c+=n;
                if(c==0)
                {
                    r=i;
                    if(l==-1)
                    {
                        l=r;
                    }
                    ret.push_back({l,r});
                    l=-1;
                }
            }
        }
        return ret;
    }
};
