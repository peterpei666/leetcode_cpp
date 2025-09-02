#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k)
    {
        int n = (int)prices.size();
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += 1LL * prices[i] * strategy[i];
        }
        long long temp = 0;
        for (int i = k / 2; i < k; i++)
        {
            temp += 1LL * prices[i];
        }
        for (int i = k; i < n; i++)
        {
            temp += 1LL * prices[i] * strategy[i];
        }
        ans = max(ans, temp);
        for (int i = 0; i < n - k; i++)
        {
            temp = temp + prices[i] * strategy[i] - prices[i + k / 2] + prices[i + k] * (1 - strategy[i + k]);
            ans = max(ans, temp);
        }
        return ans;
    }
};
