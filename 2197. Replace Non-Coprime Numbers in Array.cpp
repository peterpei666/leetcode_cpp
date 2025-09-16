#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    static inline int gcd(int a, int b)
    {
        while (b)
        {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
    
public:
    vector<int> replaceNonCoprimes(vector<int>& nums)
    {
        int n = (int)nums.size();
        int memo[n];
        memo[0] = nums[0];
        int k = 1;
        for (int i = 1; i < n; i++)
        {
            int temp = nums[i];
            while (k > 0 && gcd(memo[k - 1], temp) != 1)
            {
                temp = memo[k - 1] / gcd(memo[k - 1], temp) * temp;
                k--;
            }
            memo[k] = temp;
            k++;
        }
        vector<int> ans(k);
        memcpy(&ans[0], memo, sizeof(int) * k);
        return ans;
    }
};
