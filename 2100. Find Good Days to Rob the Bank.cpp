#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time)
    {
        int n=(int)security.size();
        int prefix[n];
        int suffix[n];
        prefix[0]=1;
        for(int i=1;i<n;i++)
        {
            if(security[i]<=security[i-1])
            {
                prefix[i]=prefix[i-1]+1;
            }
            else
            {
                prefix[i]=1;
            }
        }
        suffix[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            if(security[i]<=security[i+1])
            {
                suffix[i]=suffix[i+1]+1;
            }
            else
            {
                suffix[i]=1;
            }
        }
        vector<int> ret;
        for(int i=0;i<n;i++)
        {
            if(prefix[i]>time&&suffix[i]>time)
            {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
