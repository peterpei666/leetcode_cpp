#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> ans(n);
        if (n % 2)
        {
            for (int i = 0; i < n; i++)
            {
                ans[i] = i - n / 2;
            }
        }
        else
        {
            for (int i = 0; i < n / 2; i++)
            {
                ans[i] = i - n / 2;
            }
            for (int i = n / 2; i < n; i++)
            {
                ans[i] = i - n / 2 + 1;
            }
        }
        return ans;
    }
};

