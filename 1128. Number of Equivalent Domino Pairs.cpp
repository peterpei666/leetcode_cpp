#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes)
    {
        int mp[100]={0};
        for(vector<int>& p:dominoes)
        {
            int m1=max(p[0],p[1]);
            int m2=min(p[0],p[1]);
            mp[m2*10+m1]++;
        }
        int count=0;
        for(int i:mp)
        {
            if(i>1)
            {
                count+=i*(i-1)/2;
            }
        }
        return count;
    }
};
