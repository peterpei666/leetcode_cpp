#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int prefixConnected(vector<string>& words, int k)
    {
        unordered_map<string, int> mp;
        for (auto& w : words)
        {
            if (w.size() >= k)
            {
                mp[w.substr(0, k)]++;
            }
        }
        int ans = 0;
        for (auto& [_, n] : mp)
        {
            if (n >= 2)
            {
                ans++;
            }
        }
        return ans;
    }
};
