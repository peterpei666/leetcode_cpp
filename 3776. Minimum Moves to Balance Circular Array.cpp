#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long minMoves(vector<int>& balance)
    {
        int n = (int)balance.size();
        long long total = 0;
        int idx = -1;
        for (int i = 0; i < n; i++)
        {
            total += balance[i];
            if (balance[i] < 0)
            {
                idx = i;
            }
        }
        if (idx == -1)
        {
            return 0;
        }
        if (total < 0)
        {
            return -1;
        }
        long long ans = 0;
        total = balance[idx];
        balance[idx] = 0;
        for (int i = 1; i < n; i++)
        {
            long long temp = 0;
            if (idx - i >= 0)
            {
                temp += balance[idx - i];
                balance[idx - i] = 0;
            }
            else
            {
                temp += balance[n + idx - i];
                balance[n + idx - i] = 0;
            }
            if (idx + i < n)
            {
                temp += balance[idx + i];
                balance[idx + i] = 0;
            }
            else
            {
                temp += balance[idx + i - n];
                balance[idx + i - n] = 0;
            }
            if (temp + total <= 0)
            {
                ans += i * temp;
                total += temp;
            }
            else
            {
                ans += i * -total;
                total = 0;
            }
        }
        return ans;
    }
};
