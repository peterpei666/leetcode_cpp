#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int minimumOperationsToMakeEqual(int x, int y)
    {
        int memo[10001];
        memset(memo,-1,sizeof(memo));
        memo[x]=0;
        queue<int> q;
        q.push(x);
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            if(t==y)
            {
                return memo[y];
            }
            if(t-1>0&&(memo[t-1]==-1||memo[t-1]>memo[t]+1))
            {
                memo[t-1]=memo[t]+1;
                q.push(t-1);
            }
            if(t+1<=10000&&(memo[t+1]==-1||memo[t+1]>memo[t]+1))
            {
                memo[t+1]=memo[t]+1;
                q.push(t+1);
            }
            if(t%5==0&&(memo[t/5]==-1||memo[t/5]>memo[t]+1))
            {
                memo[t/5]=memo[t]+1;
                q.push(t/5);
            }
            if(t%11==0&&(memo[t/11]==-1||memo[t/11]>memo[t]+1))
            {
                memo[t/11]=memo[t]+1;
                q.push(t/11);
            }
        }
        return memo[y];
    }
};
