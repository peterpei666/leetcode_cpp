#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    long long maxTotalValue(vector<int>& nums, int k)
    {
        int n = (int)nums.size();
        int logn = (int)log2(n) + 1;
        int min_table[n][17];
        int max_table[n][17];
        memset(min_table, 0, sizeof(min_table));
        memset(max_table, 0, sizeof(max_table));
        for (int i = 0; i < n; i++)
        {
            min_table[i][0] = nums[i];
            max_table[i][0] = nums[i];
        }
        for (int j = 1; j < logn; j++)
        {
            for (int i = 0; i <= n - (1 << j); i++)
            {
                min_table[i][j] = min(min_table[i][j - 1], min_table[i + (1 << (j - 1))][j - 1]);
                max_table[i][j] = max(max_table[i][j - 1], max_table[i + (1 << (j - 1))][j - 1]);
            }
        }
        
        function<int(int, int)> query_min = [&](int l, int r) -> int
        {
            int j = (int)log2(r - l + 1);
            return min(min_table[l][j], min_table[r - (1 << j) + 1][j]);
        };
        
        function<int(int, int)> query_max = [&](int l, int r) -> int
        {
            int j = (int)log2(r - l + 1);
            return max(max_table[l][j], max_table[r - (1 << j) + 1][j]);
        };
        
        unordered_set<long long> visited;
        priority_queue<pair<int, pair<int, int>>> pq;
        int val = query_max(0, n - 1) - query_min(0, n - 1);
        pq.push({val, {0, n - 1}});
        visited.insert(0 * 1LL * 100000 + n - 1);
        long long ans = 0;
        int cnt = 0;
        while (!pq.empty() && cnt < k)
        {
            auto [val, range] = pq.top();
            auto [l, r] = range;
            pq.pop();
            ans += val;
            cnt++;
            if (cnt == k)
            {
                break;
            }
            if (l < r && !visited.count((l + 1) * 1LL * 100000 + r))
            {
                int new_val = query_max(l + 1, r) - query_min(l + 1, r);
                pq.push({new_val, {l + 1, r}});
                visited.insert((l + 1) * 1LL * 100000 + r);
            }
            if (l < r && !visited.count(l * 1LL * 100000 + r - 1))
            {
                int new_val = query_max(l, r - 1) - query_min(l, r - 1);
                pq.push({new_val, {l, r - 1}});
                visited.insert(l * 1LL * 100000 + r - 1);
            }
        }
        return ans;
    }
};
