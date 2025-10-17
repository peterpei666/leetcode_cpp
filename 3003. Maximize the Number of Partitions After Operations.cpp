#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxPartitionsAfterOperations(const string& s, int k)
    {
        int n = (int)s.size();
        int left[10000][3] = {0};
        int right[10000][3] = {0};
        int num = 0, mask = 0, cnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int b = 1 << (s[i] - 'a');
            if ((mask & b) == 0)
            {
                cnt++;
                if (cnt <= k)
                {
                    mask |= b;
                }
                else
                {
                    num++;
                    mask = b;
                    cnt = 1;
                }
            }
            left[i + 1][0] = num;
            left[i + 1][1] = mask;
            left[i + 1][2] = cnt;
        }
        num = 0;
        mask = 0;
        cnt = 0;
        for (int i = n - 1; i > 0; i--)
        {
            int b = 1 << (s[i] - 'a');
            if ((mask & b) == 0)
            {
                cnt++;
                if (cnt <= k)
                {
                    mask |= b;
                }
                else
                {
                    num++;
                    mask = b;
                    cnt = 1;
                }
            }
            right[i - 1][0] = num;
            right[i - 1][1] = mask;
            right[i - 1][2] = cnt;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int seg = left[i][0] + right[i][0] + 2;
            int mask = left[i][1] | right[i][1];
            int cnt = __builtin_popcount(mask);
            if (left[i][2] == k && right[i][2] == k && cnt < 26)
            {
                seg++;
            }
            else if (min(cnt + 1, 26) <= k)
            {
                seg--;
            }
            ans = max(ans, seg);
        }
        return ans;
    }
};
