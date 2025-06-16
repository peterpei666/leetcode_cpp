#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
private:
    inline int getmask(int x)
    {
        int mask=0;
        for(int i=0;i<3;i++)
        {
            mask|=1<<(3*i+x%3);
            x/=3;
        }
        return mask;
    }
    
    inline bool valid_pair(int m1,int m2)
    {
        return !(m1&m2);
    }
    
    inline bool valid(int mask)
    {
        return !((mask&(mask>>3))||(mask&(mask<<3)));
    }
    
public:
    int numOfWays(int n)
    {
        const int mod=1e9+7;
        int masks[27]={0};
        for(int i=0;i<27;i++)
        {
            int mask=getmask(i);
            if(valid(mask))
            {
                masks[i]=mask;
            }
        }
        bitset<27> adj[27];
        for(int i=0;i<27;i++)
        {
            if(masks[i])
            {
                for(int j=0;j<27;j++)
                {
                    if(masks[j]&&valid_pair(masks[i],masks[j]))
                    {
                        adj[i].set(j);
                    }
                }
            }
        }
        int list[2][27]={0};
        for(int i=0;i<27;i++)
        {
            if(masks[i])
            {
                list[0][i]=1;
            }
        }
        for(int j=1;j<n;j++)
        {
            for(int i=0;i<27;i++)
            {
                list[j%2][i]=0;
                for(int k=0;k<27;k++)
                {
                    if(adj[i].test(k))
                    {
                        list[j%2][i]+=list[(j-1)%2][k];
                        list[j%2][i]%=mod;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<27;i++)
        {
            ans+=list[(n-1)%2][i];
            ans%=mod;
        }
        return ans;
    }
};
