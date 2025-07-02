#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int possibleStringCount(const string& word, int k)
    {
        const int mod=1e9+7;
        int n=(int)word.size();
        int cnt=1;
        vector<int> freq;
        for(int i=1;i<n;i++)
        {
            if(word[i]==word[i-1])
            {
                cnt++;
            }
            else
            {
                freq.push_back(cnt);
                cnt=1;
            }
        }
        freq.push_back(cnt);
        int ans=1;
        for (int i:freq)
        {
            ans=(long long)ans*i%mod;
        }
        if(freq.size()>=k)
        {
            return ans;
        }
        vector<int> f(k);
        vector<int> g(k,1);
        f[0]=1;
        int m=(int)freq.size();
        for(int i=0;i<m;i++)
        {
            vector<int> nf(k);
            for(int j=1;j<k;j++)
            {
                nf[j]=g[j-1];
                if(j-freq[i]-1>=0)
                {
                    nf[j]=(nf[j]-g[j-freq[i]-1]+mod)%mod;
                }
            }
            vector<int> ng(k);
            ng[0]=nf[0];
            for(int j=1;j<k;j++)
            {
                ng[j]=(ng[j-1]+nf[j])%mod;
            }
            f=nf;
            g=ng;
        }
        return (ans-g[k-1]+mod)%mod;
    }
};
