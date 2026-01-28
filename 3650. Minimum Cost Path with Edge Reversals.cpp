#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int minCost(int n, vector<vector<int>>& edges)
    {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& e : edges)
        {
            graph[e[0]].push_back(make_pair(e[1], e[2]));
            graph[e[1]].push_back(make_pair(e[0], e[2] * 2));
        }
        priority_queue<long long, vector<long long>, greater<>> pq;
        pq.push(0);
        int cost[n];
        memset(cost, 0x7f, sizeof(cost));
        cost[0] = 0;
        while (!pq.empty())
        {
            int temp = (int)pq.top();
            int cur = (int)(pq.top() >> 32);
            pq.pop();
            if (temp == n - 1)
            {
                break;
            }
            for (auto [next, c] : graph[temp])
            {
                if (cost[next] > cost[temp] + c)
                {
                    cost[next] = cost[temp] + c;
                    pq.push(((cur * 1LL + c) << 32) + next);
                }
            }
        }
        return cost[n - 1] == 0x7f7f7f7f ? -1 : cost[n - 1];
    }
};
