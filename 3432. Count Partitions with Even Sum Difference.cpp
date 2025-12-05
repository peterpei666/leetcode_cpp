#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    int countPartitions(vector<int>& nums)
    {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1)
        {
            return 0;
        }
        return (int)nums.size() - 1;
    }
};
