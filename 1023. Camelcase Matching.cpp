#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<bool> camelMatch(vector<string>& queries, const string& pattern)
    {
        vector<bool> ans;
        int n = (int)pattern.size();
        for (auto& s : queries)
        {
            bool t = true;
            int idx = 0;
            for (char c : s)
            {
                if (idx < n && pattern[idx] == c)
                {
                    idx++;
                }
                else if (c >= 'A' && c <= 'Z')
                {
                    t = false;
                    break;
                }
            }
            t = t && idx == n;
            ans.push_back(t);
        }
        return ans;
    }
};
