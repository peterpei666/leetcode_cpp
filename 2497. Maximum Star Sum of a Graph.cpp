#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k)
    {
        int n=(int)vals.size();
        vector<vector<int>> list(n);
        for(auto& e:edges)
        {
            list[e[0]].push_back(vals[e[1]]);
            list[e[1]].push_back(vals[e[0]]);
        }
        int m=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int sum=vals[i];
            sort(list[i].begin(),list[i].end(),greater<int>());
            int l=min(k,(int)list[i].size());
            for(int j=0;j<l;j++)
            {
                if(list[i][j]<=0)
                {
                    break;
                }
                sum+=list[i][j];
            }
            m=max(m,sum);
        }
        return m;
    }
};
