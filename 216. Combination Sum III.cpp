#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        int cur = 0;
        
        function<void()> dfs = [&]()
        {
            if (temp.size() == k && cur == n)
            {
                ans.push_back(temp);
                return;
            }
            int start = temp.empty() ? 1 : temp.back() + 1;
            for (int i = start; i <= 9; i++)
            {
                temp.push_back(i);
                cur += i;
                dfs();
                temp.pop_back();
                cur -= i;
            }
        };
        
        dfs();
        return ans;
    }
};
