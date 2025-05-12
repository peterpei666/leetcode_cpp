#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maximumSubsequenceCount(string text, string pattern)
    {
        int n=(int)text.size();
        long long cnt1=1,cnt2=1;
        long long res1=0,res2=0;
        for(int i=0;i<n;i++)
        {
            if(text[i]==pattern[1])
            {
                res1+=cnt1;
            }
            if(text[n-1-i]==pattern[0])
            {
                res2+=cnt2;
            }
            if(text[i]==pattern[0])
            {
                cnt1++;
            }
            if(text[n-1-i]==pattern[1])
            {
                cnt2++;
            }
        }
        return max(res1,res2);
    }
};
