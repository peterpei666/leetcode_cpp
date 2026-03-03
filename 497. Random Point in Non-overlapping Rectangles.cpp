#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

class Solution
{
private:
    mt19937 gen;
    uniform_int_distribution<int> dis;
    vector<vector<int>> rec;
    vector<int> pre;
    
public:
    Solution(vector<vector<int>>& rects)
    {
        random_device rd;
        gen = mt19937(rd());
        rec = rects;
        int cur = 0;
        for (const auto& r : rects)
        {
            cur += (long long)(r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            pre.push_back(cur);
        }
        dis = uniform_int_distribution<>(0, pre.back() - 1);
    }
    
    vector<int> pick()
    {
        int t = dis(gen);
        int idx = (int)(upper_bound(pre.begin(), pre.end(), t) - pre.begin());
        int offset = (idx == 0) ? t : t - pre[idx - 1];
        int wid = rec[idx][2] - rec[idx][0] + 1;
        return {rec[idx][0] + (offset % wid), rec[idx][1] + (offset / wid)};
    }
};
