#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, const string& searchWord)
    {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        string cur = "";
        auto it = products.begin();
        for (char c : searchWord)
        {
            cur += c;
            vector<string> ret;
            it = lower_bound(it, products.end(), cur);
            for (int i = 0; i < 3 && it + i != products.end(); i++)
            {
                string& s = *(it + i);
                if (s.find(cur))
                {
                    break;
                }
                ret.push_back(s);
            }
            ans.push_back(ret);
        }
        return ans;
    }
};
