#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numberOfBeams(vector<string>& bank)
    {
        int ans=0,prev=0,cur;
        for(string& s:bank)
        {
            cur=0;
            for(char c:s)
            {
                cur+=c-'0';
            }
            if(cur)
            {
                ans+=prev*cur;
                prev=cur;
            }
        }
        return ans;
    }
};
