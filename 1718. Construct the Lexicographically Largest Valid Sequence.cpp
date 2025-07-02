#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    vector<int> best;
    
    bool dfs(int idx,int n,vector<int>& seq,int mask)
    {
        while(idx<2*n-1&&seq[idx])
        {
            idx++;
        }
        if(idx==2*n-1)
        {
            best=seq;
            return true;
        }
        for(int i=n;i>=1;i--)
        {
            if(mask&(1<<i))
            {
                continue;
            }
            if(i>1)
            {
                if(idx+i<2*n-1&&seq[idx+i]==0)
                {
                    seq[idx]=i;
                    seq[idx+i]=i;
                    if(dfs(idx+1,n,seq,mask|(1<<i)))
                    {
                        return true;
                    }
                    seq[idx]=0;
                    seq[idx+i]=0;
                }
            }
            else
            {
                seq[idx]=1;
                if(dfs(idx+1,n,seq,mask|(1<<i)))
                {
                    return true;
                }
                seq[idx]=0;
            }
        }
        return false;
    }
    
public:
    vector<int> constructDistancedSequence(int n)
    {
        vector<int> seq(2*n-1,0);
        dfs(0,n,seq,0);
        return best;
    }
};
