#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int dfs(pair<int,int> list[],int idx,int mask,int n)
    {
        if(idx==n)
        {
            return 0;
        }
        int maxlen=dfs(list,idx+1,mask,n);
        if((mask&list[idx].first)==0)
        {
            maxlen=max(maxlen,list[idx].second+dfs(list,idx+1,mask|list[idx].first,n));
        }
        return maxlen;
    }
    
    int maxLength(vector<string>& arr)
    {
        int n=(int)arr.size();
        pair<int,int> list[n];
        for(int i=0;i<n;i++)
        {
            int mask=0;
            bool f=true;
            for(char c:arr[i])
            {
                if(mask&(1<<(c-'a')))
                {
                    f=false;
                    break;
                }
                mask|=1<<(c-'a');
            }
            if(f)
            {
                list[i]={mask,(int)arr[i].size()};
            }
            else
            {
                list[i]={0,0};
            }
        }
        return dfs(list,0,0,n);
    }
};
