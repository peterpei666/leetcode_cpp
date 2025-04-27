#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumLines(vector<vector<int>>& s)
    {
        sort(s.begin(),s.end());
        int sz=(int)s.size();
        if(sz==1)
        {
            return 0;
        }
        int count=1;
        for(int i=2;i<sz;i++)
        {
            if((long long)(s[i-2][1]-s[i-1][1])*(long long)(s[i-1][0]-s[i][0])!=(long long)(s[i-1][1]-s[i][1])*(long long)(s[i-2][0]-s[i-1][0]))
            {
                count++;
            }
        }
        return count;
    }
};
