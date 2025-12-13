#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    static inline bool check(const string& s)
    {
        for (const char& c : s)
        {
            if (!isdigit(c) && !isalpha(c) && c != '_')
            {
                return false;
            }
        }
        return !s.empty();
    }
    
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive)
    {
        vector<string> ans;
        int n = (int)code.size();
        string t[4] = {"electronics", "grocery", "pharmacy", "restaurant"};
        for (int k = 0; k < 4; k++)
        {
            vector<string> temp;
            for (int i = 0; i < n; i++)
            {
                if (businessLine[i] == t[k] && isActive[i] && check(code[i]))
                {
                    temp.push_back(code[i]);
                }
            }
            sort(temp.begin(), temp.end());
            ans.insert(ans.end(), temp.begin(), temp.end());
        }
        return ans;
    }
};
