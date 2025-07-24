#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    static inline int cal(int a,int b,int c)
    {
        return max(a,max(b,c))-min(a,min(b,c));
    }
    
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges)
    {
        int n=(int)nums.size();
        vector<vector<int>> graph(n);
        for(auto& e:edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<int> sum(n);
        vector<int> in(n);
        vector<int> out(n);
        int cnt=0;
        
        function<void(int,int)> dfs=[&](int x,int p)
        {
            in[x]=cnt;
            cnt++;
            sum[x]=nums[x];
            for(int next:graph[x])
            {
                if(next!=p)
                {
                    dfs(next,x);
                    sum[x]^=sum[next];
                }
            }
            out[x]=cnt;
        };
        
        dfs(0,-1);
        int ans=INT_MAX;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(in[j]>in[i]&&in[j]<out[i])
                {
                    ans=min(ans,cal(sum[0]^sum[i],sum[i]^sum[j],sum[j]));
                }
                else if(in[i]>in[j]&&in[i]<out[j])
                {
                    ans=min(ans,cal(sum[0]^sum[j],sum[j]^sum[i],sum[i]));
                }
                else
                {
                    ans=min(ans,cal(sum[0]^sum[i]^sum[j],sum[i],sum[j]));
                }
            }
        }
        return ans;
    }
};
