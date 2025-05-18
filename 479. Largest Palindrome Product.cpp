#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int largestPalindrome(int n)
    {
        if(n==1)
        {
            return 9;
        }
        const int mod=1337;
        int low=pow(10,n-1);
        int high=pow(10,n)-1;
        for(int i=high;i>=low;i--)
        {
            string s=to_string(i);
            string r=s;
            reverse(r.begin(),r.end());
            s+=r;
            long long temp=stoll(s);
            int t=sqrtl(temp);
            for(int j=high;j>=t;j--)
            {
                if(temp%j==0&&temp/j<=high&&temp/j>=low)
                {
                    return temp%mod;
                }
            }
        }
        return 0;
    }
};
