#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthAfterTransformations(string& s, int t)
    {
        long long list[26]={0};
        long long newlist[26]={0};
        const int MOD=1e9+7;
        for(char c:s)
        {
            list[c-'a']++;
        }
        while(t)
        {
            long long temp=list[25];
            for(int i=25;i>=1;i--)
            {
                list[i]=list[i-1];
            }
            list[0]=temp;
            list[1]+=temp;
            list[1]%=MOD;
            t--;
        }
        long long sum=0;
        for(int i=0;i<26;i++)
        {
            sum+=list[i];
        }
        return sum%MOD;
    }
};
