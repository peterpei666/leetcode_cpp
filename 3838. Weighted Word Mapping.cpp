#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights)
    {
        int n = (int)words.size();
        string ans;
        for (int i = 0; i < n; i++)
        {
            int val = 0;
            int sz = (int)words[i].size();
            for (int j = 0; j < sz; j++)
            {
                val += weights[words[i][j] - 'a'];
            }
            ans += 'z' - val % 26;
        }
        return ans;
    }
};
