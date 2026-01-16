#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences)
    {
        hFences.push_back(1);
        hFences.push_back(m);
        sort(hFences.begin(), hFences.end());
        vFences.push_back(1);
        vFences.push_back(n);
        sort(vFences.begin(), vFences.end());
        unordered_set<int> mp;
        int hs = (int)hFences.size();
        int vs = (int)vFences.size();
        for (int i = 0; i < hs; i++)
        {
            for (int j = i + 1; j < hs; j++)
            {
                mp.insert(hFences[j] - hFences[i]);
            }
        }
        int ans = -1;
        for (int i = 0; i < vs; i++)
        {
            for (int j = i + 1; j < vs; j++)
            {
                
                if (mp.count(vFences[j] - vFences[i]))
                {
                    ans = max(ans, vFences[j] - vFences[i]);
                }
            }
        }
        const int mod = 1e9 + 7;
        return ans == -1 ? -1 : ((long long)ans * ans) % mod;
    }
};
