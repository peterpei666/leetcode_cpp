#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findJudge(int n, vector<vector<int>>& trust)
    {
        vector<int> er(n+1,0);
        vector<int> ee(n+1,0);
        for(auto& t:trust)
        {
            er[t[0]]++;
            ee[t[1]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(ee[i]==n-1&&er[i]==0)
            {
                return i;
            }
        }
        return -1;
    }
};
