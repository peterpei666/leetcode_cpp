#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
    int countDays(int days, vector<vector<int>>& meetings)
    {
        int prev=days;
        map<int,int> mp;
        for(vector<int>& m:meetings)
        {
            prev=min(prev,m[0]);
            mp[m[0]]++;
            mp[m[1]+1]--;
        }
        int prefix=0,free=prev;
        for(auto& [d,n]:mp)
        {
            if(prefix==0)
            {
                free+=d-prev;
            }
            prefix+=n;
            prev=d;
        }
        free+=days-prev;
        return free;
    }
};
