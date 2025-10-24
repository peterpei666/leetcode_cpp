#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int nextBeautifulNumber(int n)
    {
        static int temp[10000];
        static int k = 0;
        
        function<void(int[8], int)> dfs1 = [&](int t[8], int cur)
        {
            bool complete = true;
            for (int i = 1; i < 8; i++)
            {
                if (t[i] > 0)
                {
                    complete = false;
                    t[i]--;
                    dfs1(t, cur * 10 + i);
                    t[i]++;
                }
            }
            if (complete)
            {
                temp[k] = cur;
                k++;
            }
        };
        
        function<void(int[8], int, int)> dfs = [&](int t[8], int cur, int sum)
        {
            for (int i = cur; i < 8; i++)
            {
                if (sum + i <= 7)
                {
                    t[i] = i;
                    dfs1(t, 0);
                    dfs(t, i + 1, sum + i);
                    t[i] = 0;
                }
            }
        };
        
        if (k == 0)
        {
            int t[8] = {0};
            dfs(t, 1, 0);
            sort(&temp[0], &temp[0] + k);
        }
        return *upper_bound(&temp[0], &temp[0] + k, n);
    }
};
