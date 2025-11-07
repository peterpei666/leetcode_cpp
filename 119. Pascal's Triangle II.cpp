#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int n)
    {
        vector<int> ans;
        for (int i = 1; i <= n + 1; i++)
        {
            vector<int> temp(i);
            temp[0] = 1;
            temp[i - 1] = 1;
            for (int j = 1; j < i - 1; j++)
            {
                temp[j] = ans[j - 1] + ans[j];
            }
            ans.swap(temp);
        }
        return ans;
    }
};
