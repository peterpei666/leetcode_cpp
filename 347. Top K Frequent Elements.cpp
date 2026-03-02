#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> mp;
        for (auto& i : nums)
        {
            mp[i]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (auto& [x, n] : mp)
        {
            pq.push(make_pair(n, x));
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        vector<int> ans(k);
        for (int i = 0; i < k; i++)
        {
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};
