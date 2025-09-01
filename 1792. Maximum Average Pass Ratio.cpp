#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents)
    {
        int n = (int)classes.size();
        priority_queue<pair<double, int>> pq;
        for (int i = 0; i < n; i++)
        {
            double temp = (classes[i][0] + 1) / 1.0 / (classes[i][1] + 1) - classes[i][0] / 1.0 / classes[i][1];
            pq.push({temp, i});
        }
        while (extraStudents)
        {
            auto [_, id] = pq.top();
            pq.pop();
            classes[id][0]++;
            classes[id][1]++;
            extraStudents--;
            double temp = (classes[id][0] + 1) / 1.0 / (classes[id][1] + 1) - classes[id][0] / 1.0 / classes[id][1];
            pq.push({temp, id});
        }
        double ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += classes[i][0] / 1.0 / classes[i][1];
        }
        return ans / n;
    }
};
