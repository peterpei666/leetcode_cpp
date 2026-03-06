#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles)
    {
        unordered_map<int, int> mp;
        for (auto& s : words)
        {
            int mask = 0;
            for (char c : s)
            {
                mask |= 1 << (c - 'a');
            }
            if (__builtin_popcount(mask) <= 7)
            {
                mp[mask]++;
            }
        }
        int n = (int)puzzles.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            int mask = 0;
            for (char c : puzzles[i])
            {
                mask |= 1 << (c - 'a');
            }
            int task = 1 << (puzzles[i][0] - 'a');
            int temp = mask;
            while (temp > 0)
            {
                if ((temp & task) && mp.count(temp))
                {
                    ans[i] += mp[temp];
                }
                temp = (temp - 1) & mask;
            }
        }
        return ans;
    }
};
