#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int getLeastFrequentDigit(int n)
    {
        int cnt[10] = {0};
        while (n)
        {
            cnt[n % 10]++;
            n /= 10;
        }
        int p = -1;
        for (int i = 0; i < 10; i++)
        {
            if (cnt[i] == 0)
            {
                continue;
            }
            if (p == -1 || cnt[i] < cnt[p])
            {
                p = i;
            }
        }
        return p;
    }
};
