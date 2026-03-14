#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    void generate(const string& s, vector<string>& mp, int n)
    {
        if (s.size() == n)
        {
            mp.push_back(s);
            return;
        }
        for (char c = 'a'; c <= 'c'; c++)
        {
            if (s.empty() || s.back() != c)
            {
                generate(s + c, mp, n);
            }
        }
    }
    
public:
    string getHappyString(int n, int k)
    {
        vector<string> mp;
        generate("", mp, n);
        sort(mp.begin(), mp.end());
        if (k > mp.size())
        {
            return "";
        }
        return mp[k - 1];
    }
};
