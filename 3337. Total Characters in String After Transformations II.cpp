#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    using matrix=vector<vector<long long>>;
    const int MOD=1e9+7;
    
    matrix multiply(matrix& x,matrix& y)
    {
        int n=(int)x.size();
        matrix ret(n,vector<long long>(n,0));
        for(int i=0;i<n;i++)
        {
            for (int k=0;k<n;k++)
            {
                for (int j=0;j<n;j++)
                {
                    ret[i][j]=(ret[i][j]+x[i][k]*y[k][j])%MOD;
                }
            }
        }
        return ret;
    }
    
    matrix power(matrix base,int pow)
    {
        int n=(int)base.size();
        matrix ret(n,vector<long long>(n,0));
        for(int i=0;i<n;i++)
        {
            ret[i][i]=1;
        }
        while(pow)
        {
            if(pow&1)
            {
                ret=multiply(base,ret);
            }
            base=multiply(base,base);
            pow>>=1;
        }
        return ret;
    }
    
public:
    int lengthAfterTransformations(string& s, int t, vector<int>& nums)
    {
        long long list[26]={0};
        for(char c:s)
        {
            list[c-'a']++;
        }
        matrix trans(26,vector<long long>(26,0));
        for(int i=0;i<26;i++)
        {
            for(int j=1;j<=nums[i];j++)
            {
                trans[i][(i+j)%26]++;
            }
        }
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                trans[i][j]%=MOD;
            }
        }
        matrix trans_t=power(trans,t);
        long long sum=0;
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                sum+=trans_t[i][j]*list[i];
            }
            sum%=MOD;
        }
        return sum%MOD;
    }
};
