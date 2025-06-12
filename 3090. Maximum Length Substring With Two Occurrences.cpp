#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumLengthSubstring(const string& s)
    {
        int n=(int)s.size();
        int cnt[26]={0};
        int ans=0;
        for(int i=0,j=0;i<n;i++)
        {
            cnt[s[i]-'a']++;
            while(cnt[s[i]-'a']>2)
            {
                cnt[s[j]-'a']--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};
