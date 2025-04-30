#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k)
    {
        for(int i=0;i<k-1;i++)
        {
            colors.push_back(colors[i]);
        }
        int len=(int)colors.size();
        int l=0,r=1,ret=0;
        while(r<len)
        {
            if(colors[r]==colors[r-1])
            {
                l=r;
                r++;
                continue;
            }
            r++;
            if(r-l>=k)
            {
                ret++;
                l++;
            }
        }
        return ret;
    }
};
