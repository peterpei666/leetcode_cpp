#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int distinctEchoSubstrings(const string& text)
    {
        unordered_set<string> mp;
        int n = (int)text.size();
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; i >= j && i + j - 1 < n; j++)
            {
                if (text.compare(i - j, j, text, i, j) == 0)
                {
                    mp.insert(text.substr(i, j));
                }
            }
        }
        return (int)mp.size();
    }
};
