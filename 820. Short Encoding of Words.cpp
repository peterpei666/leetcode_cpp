#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int minimumLengthEncoding(vector<string>& words)
    {
        unordered_set<string> mp(words.begin(), words.end());
        for (auto& w : mp)
        {
            for (int i = 1; i < w.size(); i++)
            {
                mp.erase(w.substr(i));
            }
        }
        int ans = 0;
        for (auto& w : mp)
        {
            ans += w.size() + 1;
        }
        return ans;
    }
};
