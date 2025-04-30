#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k)
    {
        int n=(int)quality.size();
        vector<pair<double,int>> list(n);
        for(int i=0;i<n;i++)
        {
            list[i]={(double)wage[i]/quality[i],quality[i]};
        }
        sort(list.begin(),list.end());
        int qsum=0;
        double res=1000000000000000;
        priority_queue<int> pq;
        for(auto& [r,q]:list)
        {
            pq.push(q);
            qsum+=q;
            if(pq.size()>k)
            {
                qsum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k)
            {
                res=min(res,r*qsum);
            }
        }
        return res;
    }
};
