#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int minGroupsForValidAssignment(vector<int>& balls)
    {
        unordered_map<int,int> mp;
        for(int i:balls)
        {
            mp[i]++;
        }
        int m=1000000;
        for(auto& [i,n]:mp)
        {
            m=min(m,n);
        }
        for(;m>1;m--)
        {
            int count=0,f=1;
            for(auto& [i,n]:mp)
            {
                if(n%(m+1)==0)
                {
                    count+=n/(m+1);
                }
                else if(n/(m+1)+n%(m+1)>=m&&n%m<=n/m)
                {
                    count+=min(n/(m+1)+1,n/m);
                }
                else if(n/(m+1)+n%(m+1)>=m)
                {
                    count+=n/(m+1)+1;
                }
                else if(n%m<=n/m)
                {
                    count+=n/m;
                }
                else
                {
                    f=0;
                    break;
                }
            }
            if(f)
            {
                return count;
            }
        }
        int count=0;
        for(auto& [i,n]:mp)
        {
            count+=n/2+n%2;
        }
        return count;
    }
};
