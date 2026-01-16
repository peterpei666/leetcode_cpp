#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    inline string key(string s)
    {
        int a = s[0] - 'a';
        for (char& c : s) c = (c - 'a' - a + 26) % 26 + 'a';
        return s;
    }
    
public:
    long long countPairs(vector<string>& words)
    {
        unordered_map<string, int> mp;
        for (auto& w : words)
        {
            mp[key(w)]++;
        }
        long long ans = 0;
        for (auto& [_, n] : mp)
        {
            ans += 1LL * n * (n - 1);
        }
        return ans / 2;
    }
};
