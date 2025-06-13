#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(const string& s)
    {
        int cnt[3]={0};
        int n=(int)s.size();
        int ans=0;
        for(int i=-1,j=0;j<n;j++)
        {
            while(i<n-1&&(cnt[0]==0||cnt[1]==0||cnt[2]==0))
            {
                i++;
                cnt[s[i]-'a']++;
            }
            if(cnt[0]&&cnt[1]&&cnt[2])
            {
                ans+=n-i;
            }
            else
            {
                break;
            }
            cnt[s[j]-'a']--;
        }
        return ans;
    }
};
