#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    long long maxTotal(vector<int>& value, vector<int>& limit)
    {
        unordered_map<int, priority_queue<int>> mp;
        int n = (int)value.size();
        for (int i = 0; i < n; i++)
        {
            mp[limit[i]].push(value[i]);
        }
        long long ans = 0;
        for (auto& [lim, pq] : mp)
        {
            for (int i = 0; i < lim && !pq.empty(); i++)
            {
                ans += pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};
