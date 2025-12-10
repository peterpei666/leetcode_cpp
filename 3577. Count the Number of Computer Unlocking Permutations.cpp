#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countPermutations(vector<int>& complexity)
    {
        const int n = (int)complexity.size();
        long long ans = 1;
        const int mod = 1e9 + 7;
        for (int i = 1; i < n; i++)
        {
            if (complexity[i] <= complexity[0])
            {
                return 0;
            }
            ans = (ans * i) % mod;
        }
        return ans % mod;
    }
};
