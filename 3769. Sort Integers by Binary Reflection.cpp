#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> sortByReflection(vector<int>& nums)
    {
        unordered_map<int, int> memo;
        
        function<int(int)> func = [&](int x) -> int
        {
            if (memo.count(x))
            {
                return memo[x];
            }
            int ori = x;
            vector<int> b;
            while (x)
            {
                b.push_back(x & 1);
                x >>= 1;
            }
            int ans = 0;
            for (int d : b)
            {
                ans = (ans << 1) + d;
            }
            memo[ori] = ans;
            return ans;
        };
        
        sort(nums.begin(), nums.end(), [&](const int& a, const int& b) { return func(a) != func(b) ? func(a) < func(b) : a < b;});
        return nums;
    }
};
