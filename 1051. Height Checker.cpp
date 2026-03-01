#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int heightChecker(vector<int>& heights)
    {
        int n = (int)heights.size();
        vector<int> temp(n);
        copy(heights.begin(), heights.end(), temp.begin());
        sort(temp.begin(), temp.end());
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (heights[i] != temp[i])
            {
                ans++;
            }
        }
        return ans;
    }
};
