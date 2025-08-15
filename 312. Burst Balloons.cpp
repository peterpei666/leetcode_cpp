#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int memo[501][501];
    
    int maxCoins(vector<int>& nums)
    {
        int n=(int)nums.size()+2;
        memset(memo,-1,sizeof(memo));
        int arr[n];
        arr[0]=1;
        arr[n-1]=1;
        memcpy(arr+1,&nums[0],sizeof(int)*(n-2));
        
        function<int(int,int)> dfs=[&](int i,int j) -> int
        {
            if(i>j)
            {
                return 0;
            }
            if(memo[i][j]!=-1)
            {
                return memo[i][j];
            }
            if(i==j)
            {
                int temp=arr[i];
                if(i-1>=0)
                {
                    temp*=arr[i-1];
                }
                if(i+1<n)
                {
                    temp*=arr[i+1];
                }
                memo[i][j]=temp;
                return temp;
            }
            int ans=0;
            for(int k=i;k<=j;k++)
            {
                int temp=arr[k];
                if(j+1<=n)
                {
                    temp*=arr[j+1];
                }
                if(i-1>=0)
                {
                    temp*=arr[i-1];
                }
                temp+=dfs(i,k-1)+dfs(k+1,j);
                ans=max(ans,temp);
            }
            memo[i][j]=ans;
            return ans;
        };
        
        return dfs(1,n-2);
    }
};
