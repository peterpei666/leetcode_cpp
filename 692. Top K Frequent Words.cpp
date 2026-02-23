#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        unordered_map<string, int> mp;
        for (auto& s : words)
        {
            mp[s]++;
        }
        vector<pair<int, string>> data;
        for (auto& [s, n] : mp)
        {
            data.push_back(make_pair(-n, s));
        }
        sort(data.begin(), data.end());
        vector<string> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(data[i].second);
        }
        return ans;
    }
};
