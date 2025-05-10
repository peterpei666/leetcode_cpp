#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countBalancedPermutations(string num)
    {
        int sum=0;
        int cnt[10]={0};
        for(char c:num)
        {
            sum+=c-'0';
            cnt[c-'0']++;
        }
        if(sum&1)
        {
            return 0;
        }
        int n=(int)num.size();
        int target=sum/2;
        int odd=(n+1)/2;
        int psum[11]={0};
        long long comb[odd+1][odd+1];
        long long memo[10][target + 1][odd + 1];
        const long long MOD=1e9+7;
        memset(memo,0xff,sizeof(memo));
        for(int i=0;i<=odd;i++)
        {
            comb[i][0]=1;
            comb[i][i]=1;
            for(int j=1;j<i;j++)
            {
                comb[i][j]=(comb[i-1][j]+comb[i-1][j-1])%MOD;
            }
        }
        for(int i=9;i>=0;i--)
        {
            psum[i]=psum[i+1]+cnt[i];
        }
        function<long long(int,int,int)> dfs=[&](int p,int cur,int oddcnt)->long long
        {
            if(oddcnt<0||psum[p]<oddcnt||cur>target)
            {
                return 0;
            }
            if(p>9)
            {
                return cur==target&&oddcnt==0;
            }
            if(memo[p][cur][oddcnt]!=-1)
            {
                return memo[p][cur][oddcnt];
            }
            int evencnt=psum[p]-oddcnt;
            long long res=0;
            for(int i=max(0,cnt[p]-evencnt);i<=min(cnt[p],oddcnt);i++)
            {
                long long ways=comb[oddcnt][i]*comb[evencnt][cnt[p]-i]%MOD;
                res=(res+ways*dfs(p+1,cur+i*p,oddcnt-i)%MOD)%MOD;
            }
            memo[p][cur][oddcnt]=res;
            return res;
        };
        return (int)dfs(0,0,odd);
    }
};
