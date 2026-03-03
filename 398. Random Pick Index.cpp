#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

class Solution
{
private:
    mt19937 gen;
    unordered_map<int, vector<int>> mp;
    
public:
    Solution(vector<int>& nums)
    {
        random_device rd;
        gen = mt19937(rd());
        int n = (int)nums.size();
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target)
    {
        int n = (int)mp[target].size();
        uniform_int_distribution<int> dis(0, n - 1);
        return mp[target][dis(gen)];
    }
};
