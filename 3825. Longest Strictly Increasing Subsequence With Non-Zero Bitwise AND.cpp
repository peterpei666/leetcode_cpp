#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int lis(vector<int>& nums)
    {
        vector<int> res;
        for (int i : nums)
        {
            if (res.empty() || res.back() < i)
            {
                res.push_back(i);
            }
            else
            {
                *lower_bound(res.begin(), res.end(), i) = i;
            }
        }
        return (int)res.size();
    }
    
public:
    int longestSubsequence(vector<int>& nums)
    {
        int ans = 0;
        for (int i = 0; i < 31; i++)
        {
            vector<int> sub;
            for (int k : nums)
            {
                if (k & (1 << i))
                {
                    sub.push_back(k);
                }
            }
            ans = max(ans, lis(sub));
        }
        return ans;
    }
};
