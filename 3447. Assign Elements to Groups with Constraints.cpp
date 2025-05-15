#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements)
    {
        unordered_map<int,int> mp;
        for(int i=0;i<elements.size();i++)
        {
            if(mp.count(elements[i])==0)
            {
                mp[elements[i]]=i;
            }
        }
        int n=(int)groups.size();
        vector<int> ret(n,INT_MAX);
        for(int i=0;i<n;i++)
        {
            double big=sqrt(groups[i]);
            for(int j=1;j<=big;j++)
            {
                if(groups[i]%j==0)
                {
                    if(mp.count(j))
                    {
                        ret[i]=min(ret[i],mp[j]);
                    }
                    if(mp.count(groups[i]/j))
                    {
                        ret[i]=min(ret[i],mp[groups[i]/j]);
                    }
                }
            }
            if(ret[i]==INT_MAX)
            {
                ret[i]=-1;
            }
        }
        return ret;
    }
};
