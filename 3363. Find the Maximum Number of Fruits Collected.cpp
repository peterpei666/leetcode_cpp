#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    int maxCollectedFruits(vector<vector<int>>& fruits)
    {
        int n=(int)fruits.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=fruits[i][i];
        }
        
        function<int()> dp=[&]() -> int
        {
            int pre[n];
            int cur[n];
            memset(pre,0x80,sizeof(pre));
            memset(cur,0x80,sizeof(cur));
            pre[n-1]=fruits[0][n-1];
            for(int i=1;i<n-1;i++)
            {
                for(int j=max(i+1,n-i-1);j<n;j++)
                {
                    int best=pre[j];
                    if(j>=1)
                    {
                        best=max(best,pre[j-1]);
                    }
                    if(j<n-1)
                    {
                        best=max(best,pre[j+1]);
                    }
                    cur[j]=best+fruits[i][j];
                }
                memcpy(pre,cur,sizeof(cur));
            }
            return pre[n-1];
        };
        
        ans+=dp();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(fruits[i][j],fruits[j][i]);
            }
        }
        ans+=dp();
        return ans;
    }
};
