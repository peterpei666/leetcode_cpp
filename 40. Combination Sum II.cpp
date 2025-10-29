#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> ans;
        vector<pair<int, int>> cnt;
        int k = 0;
        for (int i : candidates)
        {
            if (k == 0 || cnt[k - 1].first != i)
            {
                cnt.push_back(make_pair(i, 1));
                k++;
            }
            else
            {
                cnt[k - 1].second++;
            }
        }
        int n = (int)cnt.size();
        
        function<void(int, int)> dfs = [&](int idx, int cur)
        {
            if (cur == target)
            {
                ans.push_back(temp);
                return;
            }
            if (cur > target || idx == n)
            {
                return;
            }
            if (cnt[idx].second > 0)
            {
                temp.push_back(cnt[idx].first);
                cnt[idx].second--;
                dfs(idx, cur + cnt[idx].first);
                temp.pop_back();
                cnt[idx].second++;
            }
            dfs(idx + 1, cur);
        };
        
        dfs(0, 0);
        return ans;
    }
};
