#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(const string& s)
    {
        if (s.size() <= 10)
        {
            return {};
        }
        const int t = 0xFFFFF;
        int mask = 0;
        for (int i = 0; i < 9; i++)
        {
            mask <<= 2;
            switch (s[i])
            {
                case 'C':
                    mask += 1;
                    break;
                case 'G':
                    mask += 2;
                    break;
                case 'T':
                    mask += 3;
                    break;
            }
        }
        int n = (int)s.size();
        unordered_map<int, pair<int, int>> mp;
        for (int i = 9; i < n; i++)
        {
            mask = (mask << 2) & t;
            switch (s[i])
            {
                case 'C':
                    mask += 1;
                    break;
                case 'G':
                    mask += 2;
                    break;
                case 'T':
                    mask += 3;
                    break;
            }
            mp[mask].first++;
            mp[mask].second = i - 9;
        }
        vector<string> ans;
        for (auto& [_, p] : mp)
        {
            auto [cnt, idx] = p;
            if (cnt > 1)
            {
                ans.push_back(s.substr(idx, 10));
            }
        }
        return ans;
    }
};
