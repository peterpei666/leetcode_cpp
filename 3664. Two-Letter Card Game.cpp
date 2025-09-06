#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int score(vector<string>& cards, char x)
    {
        int cnt[10][10] = {0};
        int n = (int)cards.size();
        for (int i = 0; i < n; i++)
        {
            cnt[cards[i][0] - 'a'][cards[i][1]- 'a']++;
        }
        int a1 = 0, a2 = 0;
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < 10; i++)
        {
            if (i == x - 'a')
            {
                continue;
            }
            a1 = max(a1, cnt[i][x - 'a']);
            a2 = max(a2, cnt[x - 'a'][i]);
            sum1 += cnt[i][x - 'a'];
            sum2 += cnt[x - 'a'][i];
        }
        int ans = 0;
        for (int k1 = 0; k1 <= cnt[x - 'a'][x - 'a']; k1++)
        {
            int k2 = cnt[x - 'a'][x - 'a'] - k1;
            int temp1, temp2;
            int max1 = max(a1, k1);
            int total1 = sum1 + k1;
            if (max1 > total1 / 2)
            {
                temp1 = total1 - max1;
            }
            else
            {
                temp1 = total1 / 2;
            }
            int max2 = max(a2, k2);
            int total2 = sum2 + k2;
            if (max2 > total2 / 2)
            {
                temp2 = total2 - max2;
            }
            else
            {
                temp2 = total2 / 2;
            }
            ans = max(ans, temp1 + temp2);
        }
        return ans;
    }
};
