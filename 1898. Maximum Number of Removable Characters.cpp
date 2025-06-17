#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    int maximumRemovals(const string& s,const string& p,vector<int>& removable)
    {
        int r=(int)removable.size();
        int l=0;
        int ans=0;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            bitset<100000> removed;
            for(int i=0;i<mid;i++)
            {
                removed.set(removable[i]);
            }
            vector<int> list[26];
            for(int i=0;i<s.size();i++)
            {
                if(removed.test(i)==false)
                {
                    list[s[i]-'a'].push_back(i);
                }
            }
            bool flag=true;
            for(int i=0,j=-1;i<p.size();i++)
            {
                auto temp=upper_bound(list[p[i]-'a'].begin(),list[p[i]-'a'].end(),j);
                if(temp==list[p[i]-'a'].end())
                {
                    flag=false;
                    break;
                }
                j=*temp;
            }
            if(flag)
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};
