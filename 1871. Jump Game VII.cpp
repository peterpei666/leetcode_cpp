#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    bool canReach(const string& s, int minJump, int maxJump)
    {
        bitset<100000> dp;
        dp.set(0);
        int n=(int)s.size();
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            if(i>maxJump)
            {
                cnt-=dp.test(i-maxJump-1);
            }
            if(i>=minJump)
            {
                cnt+=dp.test(i-minJump);
            }
            if(cnt&&s[i]=='0')
            {
                dp.set(i);
            }
        }
        return dp.test(n-1);
    }
};
