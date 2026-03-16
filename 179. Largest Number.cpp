#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string largestNumber(vector<int>& nums)
    {
        vector<string> strs;
        for (int i : nums)
        {
            strs.push_back(to_string(i));
        }
        sort(strs.begin(), strs.end(), [&](const string& a, const string& b) { return a + b > b + a; });
        if (strs[0] == "0")
        {
            return "";
        }
        string ans;
        for (string s : strs)
        {
            ans += s;
        }
        return ans;
    }
};
