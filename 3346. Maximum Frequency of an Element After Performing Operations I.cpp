#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations)
    {
        int n = (int)nums.size();
        const int N = 1e5 + 2;
        int freq[N] = {0};
        int sweep[N] = {0};
        int l = N, r = 1;
        for (int i = 0; i < n; i++)
        {
            freq[nums[i]]++;
            int t1 = max(1, nums[i] - k);
            int t2 = min(N - 1, nums[i] + k + 1);
            sweep[t1]++;
            sweep[t2]--;
            l = min(l, t1);
            r = max(r, t2);
        }
        int ans = 0, cnt = 0;
        for (int x = l; x <= r; x++)
        {
            cnt += sweep[x];
            ans = max(ans, freq[x] + min(cnt - freq[x], numOperations));
        }
        return ans;
    }
};
