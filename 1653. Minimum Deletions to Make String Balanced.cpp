#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumDeletions(const string& s)
    {
        int l=0,r=0;
        for(char c:s)
        {
            if(c=='a')
            {
                r++;
            }
        }
        int n=(int)s.size();
        int ans=min(n-r,r);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='b')
            {
                l++;
            }
            else
            {
                r--;
            }
            ans=min(ans,l+r);
        }
        return ans;
    }
};
