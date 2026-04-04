#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string decodeCiphertext(const string& encodedText, int m)
    {
        int n = (int)encodedText.size() / m;
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < min(m, n - i); k++)
            {
                int idx = i + k * n + k;
                ans.push_back(encodedText[idx]);
            }
        }
        while (!ans.empty() && ans[ans.size() - 1] == ' ')
        {
            ans.pop_back();
        }
        return ans;
    }
};
