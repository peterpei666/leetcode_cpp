#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads)
    {
        bitset<100> list[n];
        for(auto& r:roads)
        {
            list[r[0]].set(r[1]);
            list[r[1]].set(r[0]);
        }
        int rank[n];
        for(int i=0;i<n;i++)
        {
            rank[i]=(int)list[i].count();
        }
        int m=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                m=max(m,rank[i]+rank[j]-list[i].test(j));
            }
        }
        return m;
    }
};
