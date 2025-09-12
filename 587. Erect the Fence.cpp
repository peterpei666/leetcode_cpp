#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
private:
    static inline int cmp(vector<int>& p1, vector<int>& p2, vector<int>& p3)
    {
        return (p3[1] - p2[1]) * (p2[0] - p1[0]) - (p2[1] - p1[1]) * (p3[0] - p2[0]);
    }
    
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees)
    {
        sort(trees.begin(), trees.end());
        vector<vector<int>> upper;
        vector<vector<int>> lower;
        for (auto& p : trees)
        {
            while (upper.size() >= 2 && cmp(upper[upper.size() - 2], upper[upper.size() - 1], p) > 0)
            {
                upper.pop_back();
            }
            upper.push_back(p);
            while (lower.size() >= 2 && cmp(lower[lower.size() - 2], lower[lower.size() - 1], p) < 0)
            {
                lower.pop_back();
            }
            lower.push_back(p);
        }
        bitset<11000> mp;
        for (auto& p : upper)
        {
            mp.set(p[0] * 101 + p[1]);
        }
        for (auto& p : lower)
        {
            mp.set(p[0] * 101 + p[1]);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < 11000; i++)
        {
            if (mp.test(i))
            {
                ans.push_back({i / 101, i % 101});
            }
        }
        return ans;
    }
};
