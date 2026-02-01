#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long minimumCost(const string& source, const string& target, vector<char>& original, vector<char>& changed, vector<int>& cost)
    {
        int n = (int)original.size();
        int m = (int)source.size();
        int dis[26][26];
        memset(dis, 0x7f, sizeof(dis));
        for (int i = 0; i < 26; i++)
        {
            dis[i][i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            dis[original[i] - 'a'][changed[i] - 'a'] = min(dis[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }
        for (int k = 0; k < 26; k++)
        {
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    dis[i][j] = (int)min(1LL * dis[i][j], 1LL * dis[i][k] + dis[k][j]);
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < m; i++)
        {
            int x = source[i] - 'a';
            int y = target[i] - 'a';
            if (dis[x][y] == 0x7f7f7f7f)
            {
                return -1;
            }
            ans += dis[x][y];
        }
        return ans;
    }
};
