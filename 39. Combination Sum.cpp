#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> ans;
        int n = (int)candidates.size();
        
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
            temp.push_back(candidates[idx]);
            dfs(idx, cur + candidates[idx]);
            temp.pop_back();
            dfs(idx + 1, cur);
        };
        
        dfs(0, 0);
        return ans;
    }
};
