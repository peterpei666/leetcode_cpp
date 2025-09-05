#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int findRotateSteps(const string& ring, const string& key)
    {
        using state = tuple<int, int, int>;
        vector<int> mp[26];
        int n = (int)ring.size();
        int m = (int)key.size();
        for (int i = 0; i < n; i++)
        {
            mp[ring[i] - 'a'].push_back(i);
        }
        priority_queue<state, vector<state>, greater<>> pq;
        pq.push({0, 0, 0});
        int dist[m + 1][n];
        memset(dist, 0x7f, sizeof(dist));
        dist[0][0] = 0;
        while (!pq.empty())
        {
            auto [step, i, j] = pq.top();
            pq.pop();
            if (i == m)
            {
                return step;
            }
            if (dist[i][j] < step)
            {
                continue;
            }
            for (int next : mp[key[i] - 'a'])
            {
                int nstep = step + 1 + min(abs(next - j), n - abs(next - j));
                if (nstep < dist[i + 1][next])
                {
                    dist[i + 1][next] = nstep;
                    pq.push({nstep, i + 1, next});
                }
            }
        }
        return -1;
    }
};
