#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    int countLatticePoints(vector<vector<int>>& circles)
    {
        bitset<201> find[201];
        for(auto& c:circles)
        {
            for(int i=0;i<=c[2];i++)
            {
                int d=sqrt(c[2]*c[2]-i*i);
                for(int j=c[1]-d;j<=c[1];j++)
                {
                    find[c[0]+i].set(j);
                    find[c[0]+i].set(2*c[1]-j);
                    find[c[0]-i].set(j);
                    find[c[0]-i].set(2*c[1]-j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<=200;i++)
        {
            ans+=(int)find[i].count();
        }
        return ans;
    }
};
