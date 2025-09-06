#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int removeBoxes(vector<int>& boxes)
    {
        unordered_map<string, int> memo;
        
        function<int(int,int,int)> dp = [&](int l, int r, int k) -> int
        {
            if (l > r)
            {
                return 0;
            }
            string temp = to_string(l) + "," + to_string(r) + "," + to_string(k);
            if (memo.count(temp))
            {
                return memo[temp];
            }
            while (l + 1 <= r && boxes[l] == boxes[l + 1])
            {
                l++;
                k++;
            }
            int ans = dp(l + 1, r, 0) + (k + 1) * (k + 1);
            for (int m = l + 1; m <= r; m++)
            {
                if (boxes[l] == boxes[m])
                {
                    ans = max(ans, dp(m, r, k + 1) + dp(l + 1, m - 1, 0));
                }
            }
            memo[temp] = ans;
            return ans;
        };
        
        return dp(0, (int)boxes.size() - 1, 0);
    }
};
