#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long minimumMoney(vector<vector<int>>& transactions)
    {
        long long max_cost=0;
        long long total_loss=0;
        for(auto& t:transactions)
        {
            if(t[1]<t[0])
            {
                total_loss+=t[0]-t[1];
                max_cost=max(max_cost,(long long)t[1]);
            }
            else
            {
                max_cost=max(max_cost,(long long)t[0]);
            }
        }
        return total_loss+max_cost;
    }
};
