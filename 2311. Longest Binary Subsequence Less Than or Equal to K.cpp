#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestSubsequence(const string& s, int k)
    {
        int cnt=0,cur=0;
        int bit=32-__builtin_clz(k);
        int n=(int)s.size();
        for(int i=0;i<n;i++)
        {
            char c=s[n-1-i];
            if(c=='1')
            {
                if(i<bit&&cur+(1<<i)<=k)
                {
                    cur+=1<<i;
                    cnt++;
                }
            }
            else
            {
                cnt++;
            }
        }
        return cnt;
    }
};
