#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <bitset>
using namespace std;

class Solution
{
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships)
    {
        int m = (int)languages.size();
        vector<unordered_set<int>> mp(m + 1);
        for (int i = 1; i <= m; i++)
        {
            for (int lan : languages[i - 1])
            {
                mp[i].insert(lan);
            }
        }
        int k = (int)friendships.size();
        int ans = m;
        bitset<501> valid;
        for (int i = 0; i < k; i++)
        {
            for (int lan : languages[friendships[i][0] - 1])
            {
                if (mp[friendships[i][1]].count(lan))
                {
                    valid.set(i);
                    break;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            bitset<501> taught;
            for (int j = 0; j < k; j++)
            {
                if (valid.test(j))
                {
                    continue;
                }
                if (!mp[friendships[j][0]].count(i))
                {
                    taught.set(friendships[j][0]);
                }
                if (!mp[friendships[j][1]].count(i))
                {
                    taught.set(friendships[j][1]);
                }
            }
            ans = min(ans, (int)taught.count());
        }
        return ans;
    }
};
